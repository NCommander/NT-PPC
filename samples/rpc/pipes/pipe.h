/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:44:02 2023
 */
/* Compiler settings for pipe.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __pipe_h__
#define __pipe_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __pipe_sample_INTERFACE_DEFINED__
#define __pipe_sample_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: pipe_sample
 * at Sun Mar 19 11:44:02 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][version][unique][uuid] */ 


typedef struct pipe_CHAR_PIPE_TYPE
    {
    void (__RPC_FAR * pull) (
        char __RPC_FAR * state,
        unsigned char __RPC_FAR * buf,
        unsigned long esize,
        unsigned long __RPC_FAR * ecount );
    void (__RPC_FAR * push) (
        char __RPC_FAR * state,
        unsigned char __RPC_FAR * buf,
        unsigned long ecount );
    void (__RPC_FAR * alloc) (
        char __RPC_FAR * state,
        unsigned long bsize,
        unsigned char __RPC_FAR * __RPC_FAR * buf,
        unsigned long __RPC_FAR * bcount );
    char __RPC_FAR * state;
    } 	CHAR_PIPE_TYPE;

void ScrambleFile( 
    /* [in] */ unsigned long Action,
    /* [out][in] */ CHAR_PIPE_TYPE __RPC_FAR *pipe_data);

void ShutDown( void);


extern handle_t global_pipe_sample_handle;


extern RPC_IF_HANDLE pipe_sample_v1_0_c_ifspec;
extern RPC_IF_HANDLE pipe_sample_v1_0_s_ifspec;
#endif /* __pipe_sample_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
