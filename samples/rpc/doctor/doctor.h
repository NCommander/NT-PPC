/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:39:09 2023
 */
/* Compiler settings for doctor.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __doctor_h__
#define __doctor_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __doctor_INTERFACE_DEFINED__
#define __doctor_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: doctor
 * at Sun Mar 19 11:39:09 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][unique][version][uuid] */ 


#define	STRSIZE	( 500 )

void Analyze( 
    /* [size_is][string][out][in] */ unsigned char __RPC_FAR *pszInOut);

void Shutdown( void);


extern handle_t doctor_IfHandle;


extern RPC_IF_HANDLE doctor_ClientIfHandle;
extern RPC_IF_HANDLE doctor_ServerIfHandle;
#endif /* __doctor_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
