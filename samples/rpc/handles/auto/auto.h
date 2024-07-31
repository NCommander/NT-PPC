/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:40:01 2023
 */
/* Compiler settings for auto.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __auto_h__
#define __auto_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __autoh_INTERFACE_DEFINED__
#define __autoh_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: autoh
 * at Sun Mar 19 11:40:01 2023
 * using MIDL 3.00.44
 ****************************************/
/* [auto_handle][unique][version][uuid] */ 


void GetTime( 
    /* [out] */ long __RPC_FAR *time);

void Shutdown( void);



extern RPC_IF_HANDLE autoh_ClientIfHandle;
extern RPC_IF_HANDLE autoh_ServerIfHandle;
#endif /* __autoh_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
