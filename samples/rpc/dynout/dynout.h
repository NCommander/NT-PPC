/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:39:44 2023
 */
/* Compiler settings for dynout.idl:
    Os (OptLev=s), W1, Zp1, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __dynout_h__
#define __dynout_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __MemStuff_INTERFACE_DEFINED__
#define __MemStuff_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: MemStuff
 * at Sun Mar 19 11:39:44 2023
 * using MIDL 3.00.44
 ****************************************/
/* [auto_handle][unique][version][uuid] */ 


short GrabChunk( 
    /* [out] */ long __RPC_FAR *lSize,
    /* [size_is][size_is][out] */ unsigned char __RPC_FAR *__RPC_FAR *ppData);



extern RPC_IF_HANDLE MemStuff_v1_0_c_ifspec;
extern RPC_IF_HANDLE MemStuff_v1_0_s_ifspec;
#endif /* __MemStuff_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
