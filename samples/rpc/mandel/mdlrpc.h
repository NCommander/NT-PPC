/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:42:03 2023
 */
/* Compiler settings for mdlrpc.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext, oldnames
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __mdlrpc_h__
#define __mdlrpc_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __mdlrpc_INTERFACE_DEFINED__
#define __mdlrpc_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: mdlrpc
 * at Sun Mar 19 11:42:03 2023
 * using MIDL 3.00.44
 ****************************************/
/* [implicit_handle][unique][version][uuid] */ 


typedef struct  _cpoint
    {
    double real;
    double imag;
    }	CPOINT;

typedef CPOINT __RPC_FAR *PCPOINT;

typedef struct  _LONGRECT
    {
    long xLeft;
    long yBottom;
    long xRight;
    long yTop;
    }	LONGRECT;

typedef LONGRECT __RPC_FAR *PLONGRECT;

typedef unsigned short __RPC_FAR LINEBUF[ 1200 ];

void MandelCalc( 
    /* [in] */ PCPOINT pcptLL,
    /* [in] */ PLONGRECT prcDraw,
    /* [in] */ double precision,
    /* [in] */ unsigned long ulThreshold,
    /* [ref][out] */ LINEBUF __RPC_FAR *pbBuf);


extern handle_t hMandel;


extern RPC_IF_HANDLE mdlrpc_ClientIfHandle;
extern RPC_IF_HANDLE mdlrpc_ServerIfHandle;
#endif /* __mdlrpc_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
