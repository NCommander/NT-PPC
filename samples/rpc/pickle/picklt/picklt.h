/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:43:46 2023
 */
/* Compiler settings for picklt.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#include "midles.h"

#ifndef __picklt_h__
#define __picklt_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __type_pickle_INTERFACE_DEFINED__
#define __type_pickle_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: type_pickle
 * at Sun Mar 19 11:43:46 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][unique][version][uuid] */ 


#define	ARR_SIZE	( 4 )

#define	BUFSIZE	( 1024 )

typedef struct  _OBJECT1
    {
    long al[ 4 ];
    unsigned short s;
    }	OBJECT1;

typedef /* [decode][encode] */ struct  _OBJECT2
    {
    unsigned short sData;
    OBJECT1 __RPC_FAR *pObject1;
    }	OBJECT2;


extern handle_t ImplicitPicHandle;


extern RPC_IF_HANDLE type_pickle_ClientIfHandle;
extern RPC_IF_HANDLE type_pickle_ServerIfHandle;
#endif /* __type_pickle_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */


size_t
OBJECT2_AlignSize(
    OBJECT2 __RPC_FAR * _pType);


void
OBJECT2_Encode(
    OBJECT2 __RPC_FAR * _pType);


void
OBJECT2_Decode(
    OBJECT2 __RPC_FAR * _pType);

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
