@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by BIJ.HPJ. >"hlp\BIJ.hm"
echo. >>"hlp\BIJ.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\BIJ.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\BIJ.hm"
echo. >>"hlp\BIJ.hm"
echo // Prompts (IDP_*) >>"hlp\BIJ.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\BIJ.hm"
echo. >>"hlp\BIJ.hm"
echo // Resources (IDR_*) >>"hlp\BIJ.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\BIJ.hm"
echo. >>"hlp\BIJ.hm"
echo // Dialogs (IDD_*) >>"hlp\BIJ.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\BIJ.hm"
echo. >>"hlp\BIJ.hm"
echo // Frame Controls (IDW_*) >>"hlp\BIJ.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\BIJ.hm"
REM -- Make help for Project BIJ


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\BIJ.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\BIJ.hlp" goto :Error
if not exist "hlp\BIJ.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\BIJ.hlp" Debug
if exist Debug\nul copy "hlp\BIJ.cnt" Debug
if exist Release\nul copy "hlp\BIJ.hlp" Release
if exist Release\nul copy "hlp\BIJ.cnt" Release
echo.
goto :done

:Error
echo hlp\BIJ.hpj(1) : error: Problem encountered creating help file

:done
echo.
