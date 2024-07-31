/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:43:13 2023
 */
/* Compiler settings for callas.idl:
    Oi (OptLev=i0), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#include "rpcproxy.h"
#include "callas.h"

#define TYPE_FORMAT_STRING_SIZE   5                                 
#define PROC_FORMAT_STRING_SIZE   13                                

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


/* Object interface: IHelloCallAs, ver. 0.0,
   GUID={0xa46deb30,0x9f33,0x11cd,{0xb2,0x3f,0x00,0xaa,0x00,0x33,0x9c,0xce}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHelloCallAs_ServerInfo;

#pragma code_seg(".orpc")
/* [call_as] */ HRESULT STDMETHODCALLTYPE IHelloCallAs_RemoteHelloProc_Proxy( 
    IHelloCallAs __RPC_FAR * This,
    /* [string][in] */ unsigned char __RPC_FAR *pszString)
{
CLIENT_CALL_RETURN _RetVal;


#if defined( _ALPHA_ )
    va_list vlist;
#endif
    
#if defined( _ALPHA_ )
    va_start(vlist,pszString);
    _RetVal = NdrClientCall(
                 ( PMIDL_STUB_DESC  )&Object_StubDesc,
                 (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0],
                 vlist.a0);
#elif defined( _PPC_ ) || defined( _MIPS_ )

    _RetVal = NdrClientCall(
                 ( PMIDL_STUB_DESC  )&Object_StubDesc,
                 (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0],
                 ( unsigned char __RPC_FAR * )&This,
                 ( unsigned char __RPC_FAR * )&pszString);
#else
    _RetVal = NdrClientCall(
                 ( PMIDL_STUB_DESC  )&Object_StubDesc,
                 (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0],
                 ( unsigned char __RPC_FAR * )&This);
#endif
    return ( HRESULT  )_RetVal.Simple;
    
}

void __RPC_API
IHelloCallAs_RemoteHelloProc_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    
#ifndef _ALPHA_
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IHelloCallAs __RPC_FAR *This;
        unsigned char __RPC_FAR *pszString;
        HRESULT _RetVal;
        };
    #pragma pack()
#else
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IHelloCallAs __RPC_FAR *This;
        char Pad0[4];
        unsigned char __RPC_FAR *pszString;
        char Pad1[4];
        HRESULT _RetVal;
        };
    #pragma pack()
#endif

    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IHelloCallAs_HelloProc_Stub((IHelloCallAs *) pParamStruct->This,pParamStruct->pszString);
    
}


static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x10001, /* Ndr library version */
    0,
    0x300002c, /* MIDL Version 3.0.44 */
    0,
    0,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short IHelloCallAs_FormatStringOffsetTable[] = 
    {
    0
    };

static const STUB_THUNK IHelloCallAs_StubThunkTable[] = 
    {
    IHelloCallAs_RemoteHelloProc_Thunk
    };

static const MIDL_SERVER_INFO IHelloCallAs_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHelloCallAs_FormatStringOffsetTable[-3],
    &IHelloCallAs_StubThunkTable[-3],
    0,
    0,
    0
    };

const CINTERFACE_PROXY_VTABLE(4) _IHelloCallAsProxyVtbl = 
{
    &IID_IHelloCallAs,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IHelloCallAs_HelloProc_Proxy
};

const CInterfaceStubVtbl _IHelloCallAsStubVtbl =
{
    &IID_IHelloCallAs,
    &IHelloCallAs_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

#pragma data_seg(".rdata")

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {
			0x33,		/* FC_AUTO_HANDLE */
			0x44,		/* 68 */
/*  2 */	NdrFcShort( 0x3 ),	/* 3 */
#ifndef _ALPHA_
/*  4 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/*  6 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  8 */	NdrFcShort( 0x0 ),	/* Type Offset=0 */
/* 10 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  2 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

const CInterfaceProxyVtbl * _callas_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IHelloCallAsProxyVtbl,
    0
};

const CInterfaceStubVtbl * _callas_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IHelloCallAsStubVtbl,
    0
};

PCInterfaceName const _callas_InterfaceNamesList[] = 
{
    "IHelloCallAs",
    0
};


#define _callas_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _callas, pIID, n)

int __stdcall _callas_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_callas_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo callas_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _callas_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _callas_StubVtblList,
    (const PCInterfaceName * ) & _callas_InterfaceNamesList,
    0, // no delegation
    & _callas_IID_Lookup, 
    1,
    1
};
