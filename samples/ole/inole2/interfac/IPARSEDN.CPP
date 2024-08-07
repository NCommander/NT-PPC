/*
 * IPARSEDN.H
 *
 * Template IParseDisplayName interface implementation.
 *
 * Copyright (c)1993-1996 Microsoft Corporation, All Right Reserved
 *
 * Kraig Brockschmidt, Software Design Engineer
 * Microsoft Systems Developer Relations
 *
 * Internet  :  kraigb@microsoft.com
 * Compuserve:  >INTERNET:kraigb@microsoft.com
 */


#include "iparsedn.h"



/*
 * CImpIParseDisplayName::CImpIParseDisplayName
 * CImpIParseDisplayName::~CImpIParseDisplayName
 *
 * Parameters (Constructor):
 *  pObj            LPVOID of the object we're in.
 *  pUnkOuter       LPUNKNOWN to which we delegate.
 */

CImpIParseDisplayName::CImpIParseDisplayName(LPVOID pObj
    , LPUNKNOWN pUnkOuter)
    {
    m_cRef=0;
    m_pObj=pObj;
    m_pUnkOuter=pUnkOuter;
    return;
    }

CImpIParseDisplayName::~CImpIParseDisplayName(void)
    {
    return;
    }



/*
 * CImpIParseDisplayName::QueryInterface
 * CImpIParseDisplayName::AddRef
 * CImpIParseDisplayName::Release
 *
 * Purpose:
 *  Delegating IUnknown members for CImpIParseDisplayName.
 */

STDMETHODIMP CImpIParseDisplayName::QueryInterface(REFIID riid
    , LPVOID *ppv)
    {
    return m_pUnkOuter->QueryInterface(riid, ppv);
    }


STDMETHODIMP_(ULONG) CImpIParseDisplayName::AddRef(void)
    {
    ++m_cRef;
    return m_pUnkOuter->AddRef();
    }

STDMETHODIMP_(ULONG) CImpIParseDisplayName::Release(void)
    {
    --m_cRef;
    return m_pUnkOuter->Release();
    }







/*
 * CImpIParseDisplayName::ParseDisplayName
 *
 * Purpose:
 *  Parses an object's display name into a moniker to the object.
 *
 * Parameters:
 *  pBindCtx        LPBC to the bind context in use.
 *  pszName         LPTSTR to the display name to parse.
 *  pchEaten        ULONG * in which to store the number of
 *                  characters parsed.
 *  ppmk            LPMONIKER * in which to store the moniker.
 *
 * Return Value:
 *  HRESULT         NOERROR or a general error value.
 */

STDMETHODIMP CImpIParseDisplayName::ParseDisplayName(LPBC pBindCtx
    , LPTSTR, ULONG *, LPMONIKER *);
    {
    return ResultFromScode(E_NOTIMPL);
    }
