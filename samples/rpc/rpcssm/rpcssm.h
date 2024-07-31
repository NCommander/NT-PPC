/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:44:17 2023
 */
/* Compiler settings for rpcssm.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __rpcssm_h__
#define __rpcssm_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __rpcssm_INTERFACE_DEFINED__
#define __rpcssm_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: rpcssm
 * at Sun Mar 19 11:44:17 2023
 * using MIDL 3.00.44
 ****************************************/
/* [enable_allocate][implicit_handle][unique][version][uuid] */ 


#define	LIST_SIZE	( 4 )

typedef struct  _lbox
    {
    long data;
    struct _lbox __RPC_FAR *next;
    }	LBOX;

typedef struct _lbox __RPC_FAR *PBOX;

void InOutList( 
    /* [out][in] */ PBOX __RPC_FAR *ppBox);

void Shutdown( void);


extern handle_t hStarter;


extern RPC_IF_HANDLE rpcssm_ClientIfHandle;
extern RPC_IF_HANDLE rpcssm_ServerIfHandle;
#endif /* __rpcssm_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
