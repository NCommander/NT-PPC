/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:37:45 2023
 */
/* Compiler settings for inout.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __inout_h__
#define __inout_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __inout_INTERFACE_DEFINED__
#define __inout_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: inout
 * at Sun Mar 19 11:37:45 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][unique][version][uuid] */ 


void InOutProc( 
    /* [in] */ short s1,
    /* [out][in] */ short __RPC_FAR *ps2,
    /* [out] */ float __RPC_FAR *pf3);

void Shutdown( void);


extern handle_t inout_IfHandle;


extern RPC_IF_HANDLE inout_ClientIfHandle;
extern RPC_IF_HANDLE inout_ServerIfHandle;
#endif /* __inout_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
