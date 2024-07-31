/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:36:58 2023
 */
/* Compiler settings for call.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __call_h__
#define __call_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __callback_INTERFACE_DEFINED__
#define __callback_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: callback
 * at Sun Mar 19 11:36:58 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][unique][version][uuid] */ 


short Fibonacci( 
    /* [in] */ short nValue);

/* [callback] */ short Fibonacci2( 
    /* [in] */ short nValue);

void Shutdown( void);


extern handle_t callback_IfHandle;


extern RPC_IF_HANDLE callback_ClientIfHandle;
extern RPC_IF_HANDLE callback_ServerIfHandle;
#endif /* __callback_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
