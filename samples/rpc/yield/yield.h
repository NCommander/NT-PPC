/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:45:37 2023
 */
/* Compiler settings for yield.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __yield_h__
#define __yield_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __yield_INTERFACE_DEFINED__
#define __yield_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: yield
 * at Sun Mar 19 11:45:37 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][unique][version][uuid] */ 


void YieldProc( 
    /* [in] */ short cSeconds);

void Shutdown( void);


extern handle_t hYield;


extern RPC_IF_HANDLE yield_ClientIfHandle;
extern RPC_IF_HANDLE yield_ServerIfHandle;
#endif /* __yield_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
