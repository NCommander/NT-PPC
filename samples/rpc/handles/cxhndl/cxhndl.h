/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:40:30 2023
 */
/* Compiler settings for cxhndl.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __cxhndl_h__
#define __cxhndl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __cxhndl_INTERFACE_DEFINED__
#define __cxhndl_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: cxhndl
 * at Sun Mar 19 11:40:30 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][unique][version][uuid] */ 


#define	BUFSIZE	( 1024 )

typedef /* [context_handle] */ void __RPC_FAR *PCONTEXT_HANDLE_TYPE;

short RemoteOpen( 
    /* [out] */ PCONTEXT_HANDLE_TYPE __RPC_FAR *pphContext,
    /* [string][in] */ unsigned char __RPC_FAR *pszFile);

short RemoteRead( 
    /* [in] */ PCONTEXT_HANDLE_TYPE phContext,
    /* [out] */ unsigned char __RPC_FAR achBuf[ 1024 ],
    /* [out] */ short __RPC_FAR *pcbBuf);

short RemoteClose( 
    /* [out][in] */ PCONTEXT_HANDLE_TYPE __RPC_FAR *pphContext);

void Shutdown( void);


extern handle_t hStarter;


extern RPC_IF_HANDLE cxhndl_ClientIfHandle;
extern RPC_IF_HANDLE cxhndl_ServerIfHandle;
#endif /* __cxhndl_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

void __RPC_USER PCONTEXT_HANDLE_TYPE_rundown( PCONTEXT_HANDLE_TYPE );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
