/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:43:13 2023
 */
/* Compiler settings for callas.idl:
    Oi (OptLev=i0), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __callas_h__
#define __callas_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IHelloCallAs_FWD_DEFINED__
#define __IHelloCallAs_FWD_DEFINED__
typedef interface IHelloCallAs IHelloCallAs;
#endif 	/* __IHelloCallAs_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IHelloCallAs_INTERFACE_DEFINED__
#define __IHelloCallAs_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHelloCallAs
 * at Sun Mar 19 11:43:13 2023
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 


typedef int MyBoolean;


EXTERN_C const IID IID_IHelloCallAs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHelloCallAs : public IUnknown
    {
    public:
        virtual /* [local] */ MyBoolean STDMETHODCALLTYPE HelloProc( 
            /* [string][in] */ unsigned char __RPC_FAR *pszString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHelloCallAsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IHelloCallAs __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IHelloCallAs __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IHelloCallAs __RPC_FAR * This);
        
        /* [local] */ MyBoolean ( STDMETHODCALLTYPE __RPC_FAR *HelloProc )( 
            IHelloCallAs __RPC_FAR * This,
            /* [string][in] */ unsigned char __RPC_FAR *pszString);
        
        END_INTERFACE
    } IHelloCallAsVtbl;

    interface IHelloCallAs
    {
        CONST_VTBL struct IHelloCallAsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHelloCallAs_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHelloCallAs_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHelloCallAs_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHelloCallAs_HelloProc(This,pszString)	\
    (This)->lpVtbl -> HelloProc(This,pszString)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE IHelloCallAs_RemoteHelloProc_Proxy( 
    IHelloCallAs __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszString);


void __RPC_STUB IHelloCallAs_RemoteHelloProc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHelloCallAs_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* [local] */ MyBoolean STDMETHODCALLTYPE IHelloCallAs_HelloProc_Proxy( 
    IHelloCallAs __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszString);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IHelloCallAs_HelloProc_Stub( 
    IHelloCallAs __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszString);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
