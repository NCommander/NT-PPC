/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:39:26 2023
 */
/* Compiler settings for dynept.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __dynept_h__
#define __dynept_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __dynept_INTERFACE_DEFINED__
#define __dynept_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: dynept
 * at Sun Mar 19 11:39:26 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][unique][version][uuid] */ 


void HelloProc( 
    /* [string][in] */ unsigned char __RPC_FAR *pszString);

void Shutdown( void);


extern handle_t dynept_IfHandle;


extern RPC_IF_HANDLE dynept_ClientIfHandle;
extern RPC_IF_HANDLE dynept_ServerIfHandle;
#endif /* __dynept_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
