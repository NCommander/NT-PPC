/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Mar 19 10:45:11 2023
 */
/* Compiler settings for frcngn.idl:
    Os (OptLev=s), W1, Zp4, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IFractalEngine = {0x2a0e4f58,0x3908,0x101b,{0x89,0x63,0x00,0x00,0x0b,0x65,0xc7,0x5b}};


#ifdef __cplusplus
}
#endif

