///////////////////////////////////////////////////////////////////////////////
//
//  File Name 
//      RMSRPC.CPP
//
//  Description
//      This file implements all the remote functions available to client
//      WINDS public folder store providers. 
//      
//  Author
//      Irving De la Cruz
//
//  Revision: 1.7
//
// Written for Microsoft Windows Developer Support
// Copyright (c) 1995-1996 Microsoft Corporation. All rights reserved.
//
#include "_WINDS.H"
#include <RPC.H>
#include "WINDS.H"     // Header file generated by the MIDL compiler

///////////////////////////////////////////////////////////////////////////////
//    RemoteGetPublicFoldersList()
//
//    Parameters
//
//    Purpose
//
//    Return Value
//
long RemoteGetPublicFoldersList (short nFlags, long * pPipeNumber)
{
    long lResult = GetServiceState();
    if (lResult)
    {
        return lResult;
    }
    return lResult;
}

///////////////////////////////////////////////////////////////////////////////
//    RemoteGetPublicFolderMessages()
//
//    Parameters
//
//    Purpose
//
//    Return Value
//
long RemoteGetPublicFolderMessages (short nFlags, unsigned long ulFolderID, long * pPipeNumber)
{
    long lResult = GetServiceState();
    if (lResult)
    {
        return lResult;
    }
    return lResult;
}

// End of file for RMSRPC.CPP
