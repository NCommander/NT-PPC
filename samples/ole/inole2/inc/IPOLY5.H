/*
 * IPOLY5.H
 * Polyline Object Chapter 5
 *
 * Definition of an IPolyline interface for a Polyline object.
 * This custom interface and is only supported from DLL-based
 * objects.
 *
 * Copyright (c)1993-1996 Microsoft Corporation, All Rights Reserved
 *
 * Kraig Brockschmidt, Software Design Engineer
 * Microsoft Systems Developer Relations
 *
 * Internet  :  kraigb@microsoft.com
 * Compuserve:  >INTERNET:kraigb@microsoft.com
 */


#ifndef _IPOLY5_H_
#define _IPOLY5_H_


//Versioning.
#define VERSIONMAJOR                2
#define VERSIONMINOR                0
#define VERSIONCURRENT              0x00020000

#define CPOLYLINEPOINTS             20

//Version 2.0 Polyline Structure
typedef struct tagPOLYLINEDATA
    {
    WORD        wVerMaj;                //Major version number
    WORD        wVerMin;                //Minor version number
    WORD        cPoints;                //Number of points
    short       fReserved;              //Previously fDrawEntire
    RECTS       rc;                     //Rectangle of figure
    POINTS      rgpt[CPOLYLINEPOINTS];  //Points on 0-32767 grid

    //Version 2.0 additions
    COLORREF    rgbBackground;          //Background color
    COLORREF    rgbLine;                //Line color
    short       iLineStyle;             //Line style
    } POLYLINEDATA, *PPOLYLINEDATA;

#define CBPOLYLINEDATA   sizeof(POLYLINEDATA)



//We use the OLE 2.0 macro to define a new interface
#undef  INTERFACE
#define INTERFACE IPolylineAdviseSink5


/*
 * When someone initializes a polyline and is interested in receiving
 * notifications on events, then they provide one of these objects.
 */

DECLARE_INTERFACE_(IPolylineAdviseSink5, IUnknown)
    {
    //IUnknown members
    STDMETHOD(QueryInterface) (THIS_ REFIID, PPVOID) PURE;
    STDMETHOD_(ULONG,AddRef)  (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //Advise members.
    STDMETHOD_(void,OnPointChange)     (THIS) PURE;
    STDMETHOD_(void,OnSizeChange)      (THIS) PURE;
    STDMETHOD_(void,OnDataChange)      (THIS) PURE;
    STDMETHOD_(void,OnColorChange)     (THIS) PURE;
    STDMETHOD_(void,OnLineStyleChange) (THIS) PURE;
    };

typedef IPolylineAdviseSink5 *PPOLYLINEADVISESINK;


#undef  INTERFACE
#define INTERFACE IPolyline5

DECLARE_INTERFACE_(IPolyline5, IUnknown)
    {
    //IUnknown members
    STDMETHOD(QueryInterface) (THIS_ REFIID, PPVOID) PURE;
    STDMETHOD_(ULONG,AddRef)  (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //IPolyline members

    //File-related members use IPersistStorage

    //Data transfer members:
    STDMETHOD(DataSet)      (THIS_ PPOLYLINEDATA, BOOL, BOOL) PURE;
    STDMETHOD(DataGet)      (THIS_ PPOLYLINEDATA) PURE;
    STDMETHOD(DataSetMem)   (THIS_ HGLOBAL, BOOL, BOOL, BOOL) PURE;
    STDMETHOD(DataGetMem)   (THIS_ HGLOBAL *) PURE;
    STDMETHOD(RenderBitmap) (THIS_ HBITMAP *) PURE;
    STDMETHOD(RenderMetafile) (THIS_ HMETAFILE *) PURE;
    STDMETHOD(RenderMetafilePict) (THIS_ HGLOBAL *) PURE;

    //Manipulation members:
    STDMETHOD(Init)   (THIS_ HWND, LPRECT, DWORD, UINT) PURE;
    STDMETHOD(New)    (THIS) PURE;
    STDMETHOD(Undo)   (THIS) PURE;
    STDMETHOD(Window) (THIS_ HWND *) PURE;

    STDMETHOD(SetAdvise) (THIS_ PPOLYLINEADVISESINK) PURE;
    STDMETHOD(GetAdvise) (THIS_ PPOLYLINEADVISESINK *) PURE;

    STDMETHOD(RectGet) (THIS_ LPRECT) PURE;
    STDMETHOD(SizeGet) (THIS_ LPRECT) PURE;
    STDMETHOD(RectSet) (THIS_ LPRECT, BOOL) PURE;
    STDMETHOD(SizeSet) (THIS_ LPRECT, BOOL) PURE;

    STDMETHOD(ColorSet) (THIS_ UINT, COLORREF, COLORREF *) PURE;
    STDMETHOD(ColorGet) (THIS_ UINT, COLORREF *) PURE;

    STDMETHOD(LineStyleSet) (THIS_ UINT, UINT *) PURE;
    STDMETHOD(LineStyleGet) (THIS_ UINT *) PURE;
    };

typedef IPolyline5 *PPOLYLINE;


//Error values for data transfer functions
#define POLYLINE_E_INVALIDPOINTER   \
    MAKE_SCODE(SEVERITY_ERROR, FACILITY_ITF, 1)


//Color indices for color member functions
#define POLYLINECOLOR_BACKGROUND    0
#define POLYLINECOLOR_LINE          1


#endif //_IPOLY5_H_
