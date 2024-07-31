/* this ALWAYS GENERATED file contains the RPC server stubs */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 11:45:06 2023
 */
/* Compiler settings for wintyp.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#include <string.h>
#include "wintyp.h"

#define TYPE_FORMAT_STRING_SIZE   69                                
#define PROC_FORMAT_STRING_SIZE   11                                

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

/* Standard interface: wintyp_sample, ver. 1.0,
   GUID={0xda2a84e0,0xcabd,0x11cf,{0xa8,0xa4,0x00,0xa0,0xc9,0x03,0x84,0x50}} */


extern RPC_DISPATCH_TABLE wintyp_sample_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE wintyp_sample___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0xda2a84e0,0xcabd,0x11cf,{0xa8,0xa4,0x00,0xa0,0xc9,0x03,0x84,0x50}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    &wintyp_sample_v1_0_DispatchTable,
    0,
    0,
    0,
    0,
    0
    };
RPC_IF_HANDLE wintyp_sample_v1_0_s_ifspec = (RPC_IF_HANDLE)& wintyp_sample___RpcServerInterface;

extern const MIDL_STUB_DESC wintyp_sample_StubDesc;

void __RPC_STUB
wintyp_sample_ChangeBitmapRemote(
    PRPC_MESSAGE _pRpcMessage )
{
    BOOL _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    unsigned short action;
    HBITMAP __RPC_FAR *bitmap;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &wintyp_sample_StubDesc);
    
    bitmap = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
        
        action = *(( unsigned short __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&bitmap,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58],
                                  (unsigned char)0 );
        
        
        _RetVal = ChangeBitmapRemote(action,bitmap);
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)bitmap,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58] );
        
        _StubMsg.BufferLength += 16;
        
        _pRpcMessage->BufferLength = _StubMsg.BufferLength;
        
        _Status = I_RpcGetBuffer( _pRpcMessage ); 
        if ( _Status )
            RpcRaiseException( _Status );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *) _pRpcMessage->Buffer;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)bitmap,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( BOOL __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)bitmap,
                        &__MIDL_TypeFormatString.Format[0] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

void __RPC_STUB
wintyp_sample_ShutDown(
    PRPC_MESSAGE _pRpcMessage )
{
    MIDL_STUB_MESSAGE _StubMsg;
    RPC_STATUS _Status;
    
    ((void)(_Status));
    NdrServerInitializeNew(
                          _pRpcMessage,
                          &_StubMsg,
                          &wintyp_sample_StubDesc);
    
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

extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1];

static const MIDL_STUB_DESC wintyp_sample_StubDesc = 
    {
    (void __RPC_FAR *)& wintyp_sample___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x300002c, /* MIDL Version 3.0.44 */
    0,
    UserMarshalRoutines,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static RPC_DISPATCH_FUNCTION wintyp_sample_table[] =
    {
    wintyp_sample_ChangeBitmapRemote,
    wintyp_sample_ShutDown,
    0
    };
RPC_DISPATCH_TABLE wintyp_sample_v1_0_DispatchTable = 
    {
    2,
    wintyp_sample_table
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1] = 
        {
            
            {
            HBITMAP_UserSize
            ,HBITMAP_UserMarshal
            ,HBITMAP_UserUnmarshal
            ,HBITMAP_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {
			0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/*  2 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  4 */	NdrFcShort( 0x0 ),	/* Type Offset=0 */
/*  6 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/*  8 */	0x5b,		/* FC_END */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			0x11, 0x0,	/* FC_RP */
/*  2 */	NdrFcShort( 0x38 ),	/* Offset= 56 (58) */
/*  4 */	
			0x12, 0x0,	/* FC_UP */
/*  6 */	NdrFcShort( 0x2 ),	/* Offset= 2 (8) */
/*  8 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/* 10 */	NdrFcShort( 0x4 ),	/* 4 */
/* 12 */	NdrFcShort( 0x2 ),	/* 2 */
/* 14 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 18 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32742) */
/* 20 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 24 */	NdrFcShort( 0x4 ),	/* Offset= 4 (28) */
/* 26 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32734) */
/* 28 */	
			0x12, 0x0,	/* FC_UP */
/* 30 */	NdrFcShort( 0xc ),	/* Offset= 12 (42) */
/* 32 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 34 */	NdrFcShort( 0x1 ),	/* 1 */
/* 36 */	0x8,		/* 8 */
			0x0,		/*  */
/* 38 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 40 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 42 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 44 */	NdrFcShort( 0x18 ),	/* 24 */
/* 46 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (32) */
/* 48 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 50 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 52 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 54 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 56 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 58 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x4 ),	/* 4 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */
/* 66 */	NdrFcShort( 0xffffffc2 ),	/* Offset= -62 (4) */

			0x0
        }
    };
