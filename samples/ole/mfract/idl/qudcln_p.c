/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 10:45:12 2023
 */
/* Compiler settings for qudcln.idl:
    Os (OptLev=s), W1, Zp4, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#include "rpcproxy.h"
#include "qudcln.h"

#define TYPE_FORMAT_STRING_SIZE   1                                 
#define PROC_FORMAT_STRING_SIZE   1                                 

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IQuadrantClient, ver. 0.0,
   GUID={0x2a0e4fbc,0x3908,0x101b,{0x89,0x63,0x00,0x00,0x0b,0x65,0xc7,0x5b}} */

#pragma data_seg(".rdata")

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {

			0x0
        }
    };

const CInterfaceProxyVtbl * _qudcln_ProxyVtblList[] = 
{
    0
};

const CInterfaceStubVtbl * _qudcln_StubVtblList[] = 
{
    0
};

PCInterfaceName const _qudcln_InterfaceNamesList[] = 
{
    0
};


#define _qudcln_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _qudcln, pIID, n)

int __stdcall _qudcln_IID_Lookup( const IID * pIID, int * pIndex )
{
    return 0;
}

const ExtendedProxyFileInfo qudcln_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _qudcln_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _qudcln_StubVtblList,
    (const PCInterfaceName * ) & _qudcln_InterfaceNamesList,
    0, // no delegation
    & _qudcln_IID_Lookup, 
    0,
    1
};
