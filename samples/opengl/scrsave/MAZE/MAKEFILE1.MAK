# Microsoft Developer Studio Generated NMAKE File, Format Version 41001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (PPC) External Target" 0x0706

!IF "$(CFG)" == ""
CFG=MAKEFILE1 - Win32 (PPC) Debug
!MESSAGE No configuration specified.  Defaulting to MAKEFILE1 - Win32 (PPC)\
 Debug.
!ENDIF 

!IF "$(CFG)" != "MAKEFILE1 - Win32 (PPC) Release" && "$(CFG)" !=\
 "MAKEFILE1 - Win32 (PPC) Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "MAKEFILE1.MAK" CFG="MAKEFILE1 - Win32 (PPC) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MAKEFILE1 - Win32 (PPC) Release" (based on\
 "Win32 (PPC) External Target")
!MESSAGE "MAKEFILE1 - Win32 (PPC) Debug" (based on\
 "Win32 (PPC) External Target")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project

!IF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Release"

# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "PPCRel"
# PROP BASE Intermediate_Dir "PPCRel"
# PROP BASE Target_Dir ""
# PROP BASE Cmd_Line "NMAKE /f MAKEFILE"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "MAKEFILE.EXE"
# PROP BASE Bsc_Name "MAKEFILE.BSC"
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "PPCRel"
# PROP Intermediate_Dir "PPCRel"
# PROP Target_Dir ""
# PROP Cmd_Line "NMAKE /f MAKEFILE"
# PROP Rebuild_Opt "/a"
# PROP Target_File "MAKEFILE1.EXE"
# PROP Bsc_Name "MAKEFILE1.BSC"
OUTDIR=.\PPCRel
INTDIR=.\PPCRel

ALL : 

CLEAN : 
	-@erase 

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

!ELSEIF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Debug"

# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "PPCDbg"
# PROP BASE Intermediate_Dir "PPCDbg"
# PROP BASE Target_Dir ""
# PROP BASE Cmd_Line "NMAKE /f MAKEFILE"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "MAKEFILE.EXE"
# PROP BASE Bsc_Name "MAKEFILE.BSC"
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "PPCDbg"
# PROP Intermediate_Dir "PPCDbg"
# PROP Target_Dir ""
# PROP Cmd_Line "NMAKE /f MAKEFILE"
# PROP Rebuild_Opt "/a"
# PROP Target_File "MAKEFILE1.EXE"
# PROP Bsc_Name "MAKEFILE1.BSC"
OUTDIR=.\PPCDbg
INTDIR=.\PPCDbg

ALL : 

CLEAN : 
	-@erase 

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

!ENDIF 

################################################################################
# Begin Target

# Name "MAKEFILE1 - Win32 (PPC) Release"
# Name "MAKEFILE1 - Win32 (PPC) Debug"

!IF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Release"

".\MAKEFILE1.EXE" : 
   CD F:\MSTOOLS\samples\opengl\scrsave\MAZE
   NMAKE /f MAKEFILE

!ELSEIF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Debug"

".\MAKEFILE1.EXE" : 
   CD F:\MSTOOLS\samples\opengl\scrsave\MAZE
   NMAKE /f MAKEFILE

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\MAKEFILE

!IF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Release"

!ELSEIF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\DIALOG.CXX

!IF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Release"

!ELSEIF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\GENMAZE.C

!IF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Release"

!ELSEIF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\GLMAZE.C

!IF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Release"

!ELSEIF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PCH.C

!IF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Release"

!ELSEIF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\SLVMAZE.C

!IF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Release"

!ELSEIF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\SSMAZE.C

!IF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Release"

!ELSEIF  "$(CFG)" == "MAKEFILE1 - Win32 (PPC) Debug"

!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
