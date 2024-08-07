/*
 * PAGE.CPP
 * Patron Chapter 7
 *
 * Implementation of parts of the CPage class; those member
 * functions dealing with mouse events are in PAGEMOUS.CPP.
 *
 * Copyright (c)1993-1996 Microsoft Corporation, All Rights Reserved
 *
 * Kraig Brockschmidt, Software Design Engineer
 * Microsoft Systems Developer Relations
 *
 * Internet  :  kraigb@microsoft.com
 * Compuserve:  >INTERNET:kraigb@microsoft.com
 */


#include "patron.h"


/*
 * CPage::CPage
 * CPage::~CPage
 *
 * Constructor Parameters:
 *  dwID            DWORD identifier for this page.
 *  hWnd            HWND of the pages window (for repaints, etc).
 *  pPG             PCPages to the Pages window.
 */

//CHAPTER7MOD
CPage::CPage(DWORD dwID, HWND hWnd, PCPages pPG)
//End CHAPTER7MOD
    {
    m_dwID     =dwID;
    m_pIStorage=NULL;

    //CHAPTER7MOD
    m_cOpens=0;
    m_hWnd=hWnd;
    m_pPG=pPG;

    m_dwIDNext      =0;
    m_cTenants      =0;
    m_hWndTenantList=NULL;
    m_iTenantCur    =NOVALUE;   //Tenants are zero indexed.
    m_pTenantCur    =NULL;

    m_uHTCode=HTNOWHERE;
    m_uSizingFlags=0;
    m_fTracking=FALSE;
    m_hDC=NULL;

    m_fSizePending=FALSE;
    m_fTimer=FALSE;

    //These will be read from WIN.INI in Chapter 8.
    m_cxyDist=2;
    m_cDelay=200;
    //End CHAPTER7MOD

    return;
    }


CPage::~CPage(void)
    {
    //CHAPTER7MOD
    if (m_fTimer)
        KillTimer(m_hWnd, IDTIMER_DEBOUNCE);
    //End CHAPTER7MOD

    m_hWnd=NULL;
    Close(FALSE);
    return;
    }



/*
 * CPage::GetID
 *
 * Return Value:
 *  DWORD           dwID field in this page.  This function is only
 *                  here to avoid hiding inline implementations
 *                  in pages.h
 */

DWORD CPage::GetID(void)
    {
    return m_dwID;
    }





/*
 * CPage::FOpen
 *
 * Purpose:
 *  Retrieves the IStorage associated with this page.  The IStorage
 *  is owned by the page and thus the page always holds a reference
 *  count.  The caller should call Close or delete this page to
 *  match this open.
 *
 *  This function may be called multiple times resulting in
 *  additional reference counts on the storage each of which must be
 *  matched with a call to Close.  The last Close can be done
 *  through delete.
 *
 * Parameters:
 *  pIStorage       LPSTORAGE in which this page lives.
 *
 * Return Value:
 *  BOOL            TRUE if opening succeeds, FALSE otherwise.
 */

BOOL CPage::FOpen(LPSTORAGE pIStorage)
    {
    //CHAPTER7MOD
    HRESULT         hr=NOERROR;
    LPSTREAM        pIStream;
    DWORD           dwMode;
    TCHAR           szTemp[32];
    BOOL            fNew;
    BOOL            fCreated=FALSE;
    TENANTLIST      tl;
    PTENANTINFO     pti;
    ULONG           cb;
    LPMALLOC        pIMalloc;
    UINT            i;
    PCTenant        pTenant;

    fNew=(NULL==m_pIStorage);

    if (!fNew)
        {
        m_cOpens++;
        m_pIStorage->AddRef();
        return TRUE;
        }

    if (NULL==pIStorage)
        return FALSE;

    /*
     * Attempt to open the storage under this ID.  If none,
     * create one.  In either case, the IStorage is either
     * saved in pPage or released.
     */

    GetStorageName(szTemp);
    dwMode=STGM_TRANSACTED | STGM_READWRITE | STGM_SHARE_EXCLUSIVE;

    OLECHAR pwcsTemp[MAX_PATH];
#if defined(WIN32) && !defined(UNICODE)
    mbstowcs(pwcsTemp, szTemp, MAX_PATH);
#else
    pwcsTemp = szTemp;
#endif
    hr=pIStorage->OpenStorage(pwcsTemp, NULL, dwMode, NULL, 0
        , &m_pIStorage);

    if (FAILED(hr))
        {
        hr=pIStorage->CreateStorage(pwcsTemp, dwMode, 0, 0
            , &m_pIStorage);
        fCreated=TRUE;
        }

    if (FAILED(hr))
        return FALSE;

    m_cOpens++;

    if (NULL==m_hWndTenantList)
        {
        /*
         * The first time we open this page, create the hidden
         * listbox we'll use to track tenants.  We give it the
         * owner-draw style so we can just store pointers in it.
         */
        m_hWndTenantList=CreateWindow(TEXT("listbox")
            , TEXT("Tenant List"), WS_POPUP | LBS_OWNERDRAWFIXED
            , 0, 0, 100, 100, HWND_DESKTOP, NULL
            , m_pPG->m_hInst, NULL);

        if (NULL==m_hWndTenantList)
            return FALSE;
        }


    //If this is brand-new, we're done.
    if (fCreated)
        return TRUE;


    /*
     * Now open the stream we saved in Close and load all the
     * tenants listed in there.  If there are none, then we don't
     * have to load squat.
     */

    hr=m_pIStorage->OpenStream(SZSTREAMTENANTLIST, NULL, STGM_DIRECT
        | STGM_READ | STGM_SHARE_EXCLUSIVE, 0, &pIStream);

    if (FAILED(hr))
        return FALSE;

    if (SUCCEEDED(CoGetMalloc(MEMCTX_TASK, &pIMalloc)))
        {
        pIStream->Read(&tl, sizeof(tl), NULL);
        m_cTenants=tl.cTenants;
        m_dwIDNext=tl.dwIDNext;
        m_iTenantCur=0;

        cb=tl.cTenants*sizeof(TENANTINFO);

        if (0!=cb)
            {
            pti=(PTENANTINFO)pIMalloc->Alloc(cb);

            if (NULL!=pti)
                {
                pIStream->Read(pti, cb, NULL);

                for (i=0; i < m_cTenants; i++)
                    {
                    if (FTenantAdd(NOVALUE, (pti+i)->dwID, &pTenant))
                        pTenant->FLoad(m_pIStorage, (pti+i));
                    }

                pIMalloc->Free(pti);
                }
            }

        pIMalloc->Release();
        }

    pIStream->Release();

    //Get and select the first tenant
    if (FTenantGet(0, &m_pTenantCur, FALSE))
        m_pTenantCur->Select(TRUE);

    return TRUE;
    //End CHAPTER7MOD
    }





/*
 * CPage::Close
 *
 * Purpose:
 *  Possibly commits the storage, then releases it reversing the
 *  reference count from FOpen.
 *
 * Parameters:
 *  fCommit         BOOL indicating if we're to commit.
 *
 * Return Value:
 *  None
 */

void CPage::Close(BOOL fCommit)
    {
    if (NULL==m_pIStorage)
        return;

    if (fCommit)
        Update();

    //CHAPTER7MOD
    m_pIStorage->Release();

    //If this was the last close, make all tenants loaded->passive
    if (0==--m_cOpens)
        {
        UINT        i;
        PCTenant    pTenant;

        m_pIStorage=NULL;

        for (i=0; i < m_cTenants; i++)
            {
            if (FTenantGet(i, &pTenant, FALSE))
                {
                if (NULL!=m_hWnd)
                    {
                    //FOpen may select again, so this repaints.
                    pTenant->Select(FALSE);
                    }

                pTenant->Close(FALSE);
                delete pTenant;
                }
            }

        DestroyWindow(m_hWndTenantList);
        m_hWndTenantList=NULL;
        }
    //End CHAPTER7MOD

    return;
    }




/*
 * CPage::Update
 *
 * Purpose:
 *  Forces a common on the page if it's open.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  BOOL            TRUE if there are any open objects on this page,
 *                  that is, we should remain open.
 */

BOOL CPage::Update(void)
    {
    //CHAPTER7MOD
    BOOL            fOpen=FALSE;
    UINT            i;
    PCTenant        pTenant;
    HRESULT         hr;
    LPSTREAM        pIStream;
    TENANTLIST      tl;
    PTENANTINFO     pti;
    ULONG           cb;
    LPMALLOC        pIMalloc;

    //Walk the list of objects and update them all as well.
    for (i=0; i < m_cTenants; i++)
        {
        if (FTenantGet(i, &pTenant, FALSE))
            fOpen |= pTenant->Update();
        }

    //Now write our own stream containing the tenant list.
    hr=m_pIStorage->CreateStream(SZSTREAMTENANTLIST, STGM_CREATE
        | STGM_WRITE| STGM_DIRECT | STGM_SHARE_EXCLUSIVE, 0, 0
        , &pIStream);

    if (FAILED(hr))
        return fOpen;

    if (SUCCEEDED(CoGetMalloc(MEMCTX_TASK, &pIMalloc)))
        {
        tl.cTenants=m_cTenants;
        tl.dwIDNext=m_dwIDNext;

        pIStream->Write(&tl, sizeof(TENANTLIST), &cb);

        cb=m_cTenants*sizeof(TENANTINFO);
        pti=(PTENANTINFO)pIMalloc->Alloc(cb);

        if (NULL!=pti)
            {
            for (i=0; i < m_cTenants; i++)
                {
                FTenantGet(i, &pTenant, FALSE);
                pTenant->GetInfo((pti+i));
                }

            pIStream->Write(pti, cb, &cb);
            pIMalloc->Free(pti);
            }

        pIMalloc->Release();
        }

    pIStream->Release();

    //Now commit the whole mess and we're done
    if (NULL!=m_pIStorage)
        m_pIStorage->Commit(STGC_ONLYIFCURRENT);

    return fOpen;
    //End CHAPTER7MOD
    }





/*
 * CPage::Destroy
 *
 * Purpose:
 *  Removes this page from the given storage.  The caller should
 *  eventually delete this Page object to free the storage.
 *
 * Parameters:
 *  pIStorage       LPSTORAGE contianing this page on which to call
 *                  DestroyElement
 *
 * Return Value:
 *  None
 */

void CPage::Destroy(LPSTORAGE pIStorage)
    {
    if (NULL!=pIStorage)
        {
        TCHAR   szTemp[32];

        Close(FALSE);
        GetStorageName(szTemp);
#if defined(WIN32) && !defined(UNICODE)
        OLECHAR pwcsTemp[32];
        mbstowcs(pwcsTemp, szTemp, 32);
        pIStorage->DestroyElement(pwcsTemp);
#else
        pIStorage->DestroyElement(szTemp);
#endif
        }

    return;
    }




/*
 * CPage::GetStorageName
 *
 * Parameters:
 *  pszName         LPTSTR to a buffer in which to store the storage
 *                  name for this page.
 *
 * Return Value:
 *  UINT            Number of characters stored.
 */

UINT CPage::GetStorageName(LPTSTR pszName)
    {
    return wsprintf(pszName, TEXT("Page %lu"), m_dwID);
    }



//CHAPTER7MOD


/*
 * CPage::Draw
 *
 * Purpose:
 *  Draws the objects on this page to the given hDC.
 *
 * Parameters:
 *  hDC             HDC on which to draw.
 *  xOff, yOff      int offsets for the page.
 *  fNoColor        BOOL indicating black & white screen rendering.
 *  fPrinter        BOOL indicating hDC is on the printer.
 *
 * Return Value:
 *  None
 */

void CPage::Draw(HDC hDC, int xOff, int yOff, BOOL fNoColor
    , BOOL fPrinter)
    {
    int                 i;
    PCTenant            pTenant;
    HDC                 hIC=NULL;
    PCOMBINEDEVICE      pcd=NULL;
    DVTARGETDEVICE     *ptd=NULL;

    /*
     * If printing, tell the tenant to forget the borders. Otherwise
     * we leave xOff and yOff the same to account for scrolling.
     */
    if (fPrinter)
        {
        xOff=LOMETRIC_BORDER+m_pPG->m_xMarginLeft;
        yOff=-LOMETRIC_BORDER-m_pPG->m_yMarginTop;

        /*
         * Get device information.  If this fails, ptd is
         * NULL which is acceptable.
         */
        if (m_pPG->DevReadConfig(&pcd, &hIC))
            ptd=&(pcd->td);
        }

    for (i=(int)m_cTenants-1; i >=0; i--)
        {
        if (FTenantGet(i, &pTenant, FALSE))
            {
            RECT        rc, rcWin;
            RECTL       rcl;

            //Paint this tenant only if visible.
            pTenant->RectGet(&rcl, TRUE);
            RECTFROMRECTL(rc, rcl);
            OffsetRect(&rc, -(int)m_pPG->m_xPos
                , -(int)m_pPG->m_yPos);
            GetClientRect(m_hWnd, &rcWin);

            if (IntersectRect(&rc, &rc, &rcWin))
                {
                pTenant->Draw(hDC, ptd, hIC, xOff, yOff
                    , fNoColor, fPrinter);
                }
            }
        }

    //Free whatever CPages::DevReadConfig returned.
    if (NULL!=pcd)
        {
        LPMALLOC    pIMalloc;

        if (SUCCEEDED(CoGetMalloc(MEMCTX_TASK, &pIMalloc)))
            {
            pIMalloc->Free(pcd);
            pIMalloc->Release();
            }
        }

    if (NULL!=hIC)
        DeleteDC(hIC);

    return;
    }






/*
 * CPage::TenantCreate
 *
 * Purpose:
 *  Creates a new tenant of a specific type.
 *
 * Parameters:
 *  tType           TENANTTYPE to create.
 *  pv              LPVOID providing information for the new
 *                  object creation.
 *  pFE             LPFORMATETC describing how we want this
 *                  rendered.
 *  ppo             PPATRONOBJECT with placement data.
 *  dwData          DWORD extra data to pass to the tenant.
 *
 * Return Value:
 *  None
 */

BOOL CPage::TenantCreate(TENANTTYPE tType, LPVOID pv
    , LPFORMATETC pFE, PPATRONOBJECT ppo, DWORD dwData)
    {
    PCTenant    pTenant;
    UINT        uRet;
    int         x, y;
    int         h, v;
    POINTL      ptl;
    SIZEL       szl;
    RECTL       rcl;
    RECT        rc;

    //New tenants go at top of the pile; zero index to FTenantAdd.
    if (!FTenantAdd(0, m_dwIDNext, &pTenant))
        return FALSE;

    uRet=pTenant->UCreate(tType, pv, pFE, &ptl, &szl, m_pIStorage
        , ppo, dwData);

    if (UCREATE_FAILED==uRet)
        {
        //Reverse UCreate AND FTenantAdd
        SendMessage(m_hWndTenantList, LB_DELETESTRING, 0, 0L);
        pTenant->Destroy(m_pIStorage);

        delete pTenant;
        return FALSE;
        }

    m_dwIDNext++;
    m_cTenants++;

    if (NULL!=m_pTenantCur)
        m_pTenantCur->Select(FALSE);

    m_iTenantCur=0;             //First one in the list now.
    m_pTenantCur=pTenant;

    //Tell the tenant where it lives, default is (0,0) in print area
    x=LOMETRIC_BORDER+m_pPG->m_xMarginLeft;
    y=-LOMETRIC_BORDER-m_pPG->m_yMarginTop;

    h=x;
    v=y;

    if (UCREATE_PLACEDOBJECT==uRet)
        {
        SetRect(&rc, 3*CXYHANDLE, 3*CXYHANDLE, 0, 0);
        RectConvertMappings(&rc, NULL, FALSE);

        //Make sure place point is on page, otherwise go to (0,0)
        if (((int)ptl.x > x)
            && ((int)ptl.x < x+(int)m_pPG->m_cx-rc.left))
            x=(int)ptl.x;

        //m_pPG->m_cy is absolute
        if (((int)ptl.y < y)
            && ((int)ptl.y > y-(int)m_pPG->m_cy-rc.top))
            y=(int)ptl.y;
        }

    //Bounds check size of the object and fit to page as necessary.
    if (x+(int)szl.cx > (int)(h+m_pPG->m_cx))
        szl.cx=h+m_pPG->m_cx-x;

    //Remember that szl we get from UCreate is absolute
    if (y-(int)szl.cy < (int)(v-m_pPG->m_cy))
        szl.cy=-(int)(v-m_pPG->m_cy-y);

    SETRECTL(rcl, x, y, x+szl.cx, y-szl.cy);
    m_pTenantCur->RectSet(&rcl, FALSE);

    //Force a repaint on this new guy
    m_pTenantCur->Invalidate();
    UpdateWindow(m_hWnd);

    m_pTenantCur->Select(TRUE);
    return TRUE;
    }






/*
 * CPage::TenantDestroy
 *
 * Purpose:
 *  Destroys the currently selected tenant on this page.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  None
 */

BOOL CPage::TenantDestroy(void)
    {
    if (NULL==m_pTenantCur)
        {
        MessageBeep(0);
        return FALSE;
        }

    SendMessage(m_hWndTenantList, LB_DELETESTRING
        , m_iTenantCur, 0L);

    m_pTenantCur->Invalidate();
    m_pTenantCur->Destroy(m_pIStorage);

    delete m_pTenantCur;
    m_pTenantCur=NULL;

    //Update counts, etc., and select the next tenant in the list.
    if (m_iTenantCur==m_cTenants-1)
        m_iTenantCur--;

    if (0==--m_cTenants)
        m_pTenantCur=NULL;
    else
        {
        FTenantGet(m_iTenantCur, &m_pTenantCur, TRUE);
        m_pTenantCur->Select(TRUE);
        }

    UpdateWindow(m_hWnd);
    return TRUE;
    }





/*
 * CPage::TenantClip
 *
 * Purpose:
 *  Copies or cuts the currently selected tenant to the clipoard.
 *
 * Parameters:
 *  fCut            BOOL TRUE to cut the object, FALSE to copy.
 *
 * Return Value:
 *  BOOL            TRUE if successful, FALSE otherwise.
 */

BOOL CPage::TenantClip(BOOL fCut)
    {
    LPDATAOBJECT    pIDataObject;
    BOOL            fRet=FALSE;

    if (NULL==m_pTenantCur)
        return FALSE;

    /*
     * To perform a data transfer operation, we need to create a
     * data object with the selected object's data inside. To do
     * this we CoCreateInstance on CLSID_DataTransferObject
     * (Also implemented in this chapter), retrieve data from the
     * object we have, stuff that data into the transfer object,
     * then stick that object on the clipboard.
     *
     * Since we'll want an identical object at other times, like for
     * drag-drop, we use a private function to actually create it.
     */

    pIDataObject=TransferObjectCreate(NULL);

    if (NULL!=pIDataObject)
        {
        if (SUCCEEDED(OleSetClipboard(pIDataObject)))
            {
            if (fCut)
                TenantDestroy();

            fRet=TRUE;
            }

        pIDataObject->Release();
        }

    return fRet;
    }





/*
 * CPage::FQueryObjectSelected
 *
 * Purpose:
 *  Returns whether or not there is an object selected on this
 *  page for Cut, Copy, Delete functions.
 *
 * Parameters:
 *  hMenu           HMENU of the Edit menu.
 *
 * Return Value:
 *  BOOL            TRUE if we have an object, FALSE otherwise.
 */

BOOL CPage::FQueryObjectSelected(HMENU hMenu)
    {
    return (NULL!=m_pTenantCur);
    }






/*
 * CPages::FTenantGet
 * (Protected)
 *
 * Purpose:
 *  Returns a tenant of a given index returning a BOOL so it's
 *  simple to use this function inside if statements.
 *
 * Parameters:
 *  iTenant         UINT tenant to retrieve 0 based.
 *  ppTenant        PCPage * in which to return the tenant
 *                  pointer
 *  fOpen           BOOL indicating if we should open this
 *                  tenant as well.
 *
 * Return Value:
 *  BOOL            TRUE if successful, FALSE otherwise.
 */

BOOL CPage::FTenantGet(UINT iTenant, PCTenant *ppTenant
    , BOOL fOpen)
    {
    if (NULL==ppTenant)
        return FALSE;

    if (LB_ERR!=SendMessage(m_hWndTenantList, LB_GETTEXT
        , iTenant, (LONG)ppTenant))
        {
        if (fOpen)
            (*ppTenant)->FOpen(m_pIStorage);

        return TRUE;
        }

    return FALSE;
    }







/*
 * CPage::FTenantAdd
 * (Protected)
 *
 * Purpose:
 *  Creates a new tenant initialized to the given values.  The new
 *  tenants's storage is created if it does not already exist.  If
 *  fOpenStorage is set the the tenants's storage is opened and left
 *  opened.
 *
 * Parameters:
 *  iTenant         UINT Location at which to insert tenant; new
 *                  tenant is inserted after this position.  NOVALUE
 *                  for the end.
 *  dwID            DWORD ID for this tenant.
 *  ppNew           PCTenant * in which to store the new tenant.
 *
 * Return Value:
 *  BOOL            TRUE if the function succeeded, FALSE otherwise.
 */

BOOL CPage::FTenantAdd(UINT iTenant, DWORD dwID
    , PCTenant *ppNew)
    {
    PCTenant    pTenant;
    LRESULT     lr;

    if (NULL!=ppNew)
        *ppNew=NULL;

    pTenant=new CTenant(dwID, m_hWnd, m_pPG);

    if (NULL==pTenant)
        return FALSE;

    //Now try to add to the listbox.
    lr=SendMessage(m_hWndTenantList, LB_INSERTSTRING, iTenant
        , (LONG)pTenant);

    if (lr < 0)
        {
        delete pTenant;
        return FALSE;
        }

    *ppNew=pTenant;
    return TRUE;
    }





/*
 * CPage::TransferObjectCreate
 * (Protected)
 *
 * Purpose:
 *  Creates a DataTransferObject and stuff the current selection's
 *  data into it.
 *
 * Parameters:
 *  pptl            LPPOINTL containing the pick point in device
 *                  units applicable only to drag-drop; since
 *                  drag-drop is inherently mouse oriented, we use
 *                  device units for the point.  Ignored if NULL.
 *
 * Return Value:
 *  LPDATAOBJECT    Pointer to the object created, NULL on failure
 */

LPDATAOBJECT CPage::TransferObjectCreate(LPPOINTL pptl)
    {
    LPDATAOBJECT    pIDataObject;
    LPDATAOBJECT    pIDataT;
    PPATRONOBJECT   ppo;
    RECTL           rcl;
    LPUNKNOWN       pObj;
    FORMATETC       fe;
    STGMEDIUM       stm;
    HRESULT         hr;

    m_pTenantCur->ObjectGet(&pObj);

    hr=CoCreateInstance(CLSID_DataTransferObject, NULL
        , CLSCTX_INPROC_SERVER, IID_IDataObject
        , (PPVOID)&pIDataObject);

    if (FAILED(hr))
        return NULL;

    //Go get the data we should hold on to.
    hr=pObj->QueryInterface(IID_IDataObject, (PPVOID)&pIDataT);

    if (FAILED(hr))
        {
        pIDataObject->Release();
        pObj->Release();
        return NULL;
        }

    //Copy from known obj into transfer obj.  Ordering is important!

    //Generate placeable object structure
    stm.tymed=TYMED_HGLOBAL;
    stm.pUnkForRelease=NULL;
    stm.hGlobal=GlobalAlloc(GHND, sizeof(PATRONOBJECT));

    if (NULL==stm.hGlobal)
        {
        pIDataObject->Release();
        pObj->Release();
        return NULL;
        }

    ppo=(PPATRONOBJECT)GlobalLock(stm.hGlobal);

    m_pTenantCur->SizeGet(&ppo->szl, FALSE);
    ppo->szl.cy=-ppo->szl.cy; //Negate to make absolute size

    m_pTenantCur->RectGet(&rcl, FALSE);
    ppo->ptl.x=rcl.left;
    ppo->ptl.y=rcl.top;

    if (NULL==pptl)
        {
        ppo->ptlPick.x=0;
        ppo->ptlPick.y=0;
        }
    else
        ppo->ptlPick=*pptl;

    m_pTenantCur->FormatEtcGet(&ppo->fe, FALSE);

    GlobalUnlock(stm.hGlobal);

    SETDefFormatEtc(fe, m_pPG->m_cf, TYMED_HGLOBAL);
    pIDataObject->SetData(&fe, &stm, TRUE);


    //Copy the actual presentation.
    m_pTenantCur->FormatEtcGet(&fe, TRUE);
    pIDataT->GetData(&fe, &stm);
    pIDataObject->SetData(&fe, &stm, TRUE);

    pIDataT->Release();

    pObj->Release();
    return pIDataObject;    //Caller now responsible
    }


//End CHAPTER7MOD
