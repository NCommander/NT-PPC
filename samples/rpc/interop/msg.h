/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:41:36 2023
 */
/* Compiler settings for msg.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __msg_h__
#define __msg_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __interop_INTERFACE_DEFINED__
#define __interop_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: interop
 * at Sun Mar 19 11:41:36 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][version][uuid] */ 


void ClientMessage( 
    /* [ref][string][in] */ unsigned char __RPC_FAR *pszMessage);

void ShutdownServer( void);


extern handle_t interop_binding_handle;


extern RPC_IF_HANDLE interop_v1_0_c_ifspec;
extern RPC_IF_HANDLE interop_v1_0_s_ifspec;
#endif /* __interop_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
