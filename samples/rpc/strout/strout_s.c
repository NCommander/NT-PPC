/* this ALWAYS GENERATED file contains the RPC server stubs */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:44:51 2023
 */
/* Compiler settings for strout.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#include <string.h>
#include "strout.h"

#define TYPE_FORMAT_STRING_SIZE   43                                
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

/* Standard interface: strout_sample, ver. 1.0,
   GUID={0xcab31280,0xb996,0x11cf,{0x95,0x48,0x00,0xaa,0x00,0x37,0x4e,0x69}} */


extern RPC_DISPATCH_TABLE strout_sample_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE strout_sample___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0xcab31280,0xb996,0x11cf,{0x95,0x48,0x00,0xaa,0x00,0x37,0x4e,0x69}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &strout_sample_v1_0_DispatchTable,
    0,
    0,
    0,
    0,
    0
    };
RPC_IF_HANDLE strout_sample_v1_0_s_ifspec = (RPC_IF_HANDLE)& strout_sample___RpcServerInterface;

extern const MIDL_STUB_DESC strout_sample_StubDesc;

void __RPC_STUB
strout_sample_GetRemoteEnv(
    PRPC_MESSAGE _pRpcMessage )
{
    str __RPC_FAR *__RPC_FAR *EnvBlock;
    unsigned long __RPC_FAR *Lines;
    str __RPC_FAR *_M1;
    MIDL_STUB_MESSAGE _StubMsg;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &strout_sample_StubDesc);
    
    Lines = 0;
    EnvBlock = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
        
        Lines = ( unsigned long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( unsigned long  );
        
        EnvBlock = &_M1;
        _M1 = 0;
        
        GetRemoteEnv(Lines,EnvBlock);
        
        _StubMsg.BufferLength = 4U + 8U;
        _StubMsg.MaxCount = Lines ? *Lines : 0;
        
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)EnvBlock,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4] );
        
        _pRpcMessage->BufferLength = _StubMsg.BufferLength;
        
        _Status = I_RpcGetBuffer( _pRpcMessage ); 
        if ( _Status )
            RpcRaiseException( _Status );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *) _pRpcMessage->Buffer;
        
        *(( unsigned long __RPC_FAR * )_StubMsg.Buffer)++ = *Lines;
        
        _StubMsg.MaxCount = Lines ? *Lines : 0;
        
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)EnvBlock,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[4] );
        
        }
    RpcFinally
        {
        _StubMsg.MaxCount = Lines ? *Lines : 0;
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)EnvBlock,
                        &__MIDL_TypeFormatString.Format[4] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
strout_sample_ShutDown(
    PRPC_MESSAGE _pRpcMessage )
{
    MIDL_STUB_MESSAGE _StubMsg;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &strout_sample_StubDesc);
    
    RpcTryFinally
        {
        
        ShutDown();
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


static const MIDL_STUB_DESC strout_sample_StubDesc = 
    {
    (void __RPC_FAR *)& strout_sample___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
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

static RPC_DISPATCH_FUNCTION strout_sample_table[] =
    {
    strout_sample_GetRemoteEnv,
    strout_sample_ShutDown,
    0
    };
RPC_DISPATCH_TABLE strout_sample_v1_0_DispatchTable = 
    {
    2,
    strout_sample_table
    };

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {
			
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  2 */	NdrFcShort( 0x0 ),	/* Type Offset=0 */
/*  4 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  6 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */
/*  8 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */
/* 10 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  2 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  4 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/*  6 */	NdrFcShort( 0x2 ),	/* Offset= 2 (8) */
/*  8 */	
			0x12, 0x0,	/* FC_UP */
/* 10 */	NdrFcShort( 0x2 ),	/* Offset= 2 (12) */
/* 12 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 14 */	NdrFcShort( 0x4 ),	/* 4 */
/* 16 */	0x29,		/* 41 */
			0x54,		/* FC_DEREFERENCE */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x0 ),	/* x86, MIPS, PPC Stack size/offset = 0 */
#else
			NdrFcShort( 0x0 ),	/* Alpha Stack size/offset = 0 */
#endif
/* 20 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 22 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 24 */	NdrFcShort( 0x4 ),	/* 4 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x1 ),	/* 1 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 36 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 38 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 40 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };
