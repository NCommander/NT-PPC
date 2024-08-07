/*
 * IIPOBJ.CPP
 * Cosmo Chapter 16
 *
 * IOleInPlaceObject interface implementation for Cosmo
 *
 * Copyright (c)1993-1996 Microsoft Corporation, All Rights Reserved
 *
 * Kraig Brockschmidt, Software Design Engineer
 * Microsoft Systems Developer Relations
 *
 * Internet  :  kraigb@microsoft.com
 * Compuserve:  >INTERNET:kraigb@microsoft.com
 */


#include "cosmo.h"


/*
 * CImpIOleInPlaceObject::CImpIOleInPlaceObject
 * CImpIOleInPlaceObject::~CImpIOleInPlaceObject
 *
 * Parameters (Constructor):
 *  pObj            PCFigure of the object we're in.
 *  pUnkOuter       LPUNKNOWN to which we delegate.
 */

CImpIOleInPlaceObject::CImpIOleInPlaceObject(PCFigure pObj
    , LPUNKNOWN pUnkOuter)
    {
    m_cRef=0;
    m_pObj=pObj;
    m_pUnkOuter=pUnkOuter;
    return;
    }

CImpIOleInPlaceObject::~CImpIOleInPlaceObject(void)
    {
    return;
    }



/*
 * CImpIOleInPlaceObject::QueryInterface
 * CImpIOleInPlaceObject::AddRef
 * CImpIOleInPlaceObject::Release
 *
 * Purpose:
 *  IUnknown members for CImpIOleInPlaceObject object.
 */

STDMETHODIMP CImpIOleInPlaceObject::QueryInterface(REFIID riid
    , PPVOID ppv)
    {
    return m_pUnkOuter->QueryInterface(riid, ppv);
    }


STDMETHODIMP_(ULONG) CImpIOleInPlaceObject::AddRef(void)
    {
    ++m_cRef;
    return m_pUnkOuter->AddRef();
    }

STDMETHODIMP_(ULONG) CImpIOleInPlaceObject::Release(void)
    {
    --m_cRef;
    return m_pUnkOuter->Release();
    }




/*
 * CImpIOleInPlaceObject::GetWindow
 *
 * Purpose:
 *  Retrieves the handle of the window associated with the object
 *  on which this interface is implemented.
 *
 * Parameters:
 *  phWnd           HWND * in which to store the window handle.
 *
 * Return Value:
 *  HRESULT         NOERROR if successful, E_FAIL if there is no
 *                  window.
 */

STDMETHODIMP CImpIOleInPlaceObject::GetWindow(HWND *phWnd)
    {
    *phWnd=m_pObj->m_pHW->Window();
    return NOERROR;
    }




/*
 * CImpIOleInPlaceObject::ContextSensitiveHelp
 *
 * Purpose:
 *  Instructs the object on which this interface is implemented to
 *  enter or leave a context-sensitive help mode.
 *
 * Parameters:
 *  fEnterMode      BOOL TRUE to enter the mode, FALSE otherwise.
 *
 * Return Value:
 *  HRESULT         NOERROR or an error code
 */

STDMETHODIMP CImpIOleInPlaceObject::ContextSensitiveHelp
    (BOOL fEnterMode)
    {
    return ResultFromScode(E_NOTIMPL);
    }




/*
 * CImpIOleInPlaceObject::InPlaceDeactivate
 *
 * Purpose:
 *  Instructs the object to deactivate itself from an in-place state
 *  and to discard any Undo state.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  HRESULT         NOERROR or an error code
 */

STDMETHODIMP CImpIOleInPlaceObject::InPlaceDeactivate(void)
    {
    m_pObj->InPlaceDeactivate();
    return NOERROR;
    }




/*
 * CImpIOleInPlaceObject::UIDeactivate
 *
 * Purpose:
 *  Instructs the object to just remove any in-place user interface
 *  but to do no other deactivation.  The object should just hide
 *  the UI components but not destroy them until InPlaceDeactivate
 *  is called.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  HRESULT         NOERROR or an error code
 */

STDMETHODIMP CImpIOleInPlaceObject::UIDeactivate(void)
    {
    m_pObj->UIDeactivate();
    return NOERROR;
    }




/*
 * CImpIOleInPlaceObject::SetObjectRects
 *
 * Purpose:
 *  Provides the object with rectangles describing the position of
 *  the object in the container window as well as its visible area.
 *
 * Parameters:
 *  prcPos          LPCRECT providing the object's full rectangle
 *                  relative to the container document.  The object
 *                  should scale to this rectangle.
 *  prcClip         LPCRECT describing the visible area of the object
 *                  which should not draw outside these areas.
 *
 * Return Value:
 *  HRESULT         NOERROR or an error code
 */

STDMETHODIMP CImpIOleInPlaceObject::SetObjectRects(LPCRECT prcPos
    , LPCRECT prcClip)
    {
    /*
     * The idea here is to resize the polyline (editor) window to
     * the position rectangle as that defines the scaling.  We then
     * resize the hatch window, the parent of the editor, to the
     * intersection of the clip rectangle and the position rectangle.
     * Since the polyline is the child of the hatch window, the
     * polyline, while still scaled to the position rectangle, is
     * also clipped to the clip rectangle, providing only a partial
     * view of the correctly scaled presentation.
     *
     * The Hatch window takes care of this.
     */

    m_pObj->m_pHW->RectsSet((LPRECT)prcPos, (LPRECT)prcClip);
    return NOERROR;
    }




/*
 * CImpIOleInPlaceObject::ReactivateAndUndo
 *
 * Purpose:
 *  Instructs the object to reactivate itself in-place and perform
 *  whatever Undo means for it.
 *
 * Parameters:
 *  None
 *
 * Return Value:
 *  HRESULT         NOERROR or an error code
 */

STDMETHODIMP CImpIOleInPlaceObject::ReactivateAndUndo(void)
    {
    return m_pObj->InPlaceActivate(m_pObj->m_pIOleClientSite, TRUE);
    }
