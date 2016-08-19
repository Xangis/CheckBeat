;Include Modern UI

  !include "MUI2.nsh"
  !include "FileAssociation.nsh"

Name "CheckBeat 3"
OutFile "CheckBeat3Setup.exe"
InstallDir "$PROGRAMFILES\Zeta Centauri\CheckBeat"
InstallDirRegKey HKLM "Software\CheckBeat" "Install_Dir"
RequestExecutionLevel admin
!define MUI_ICON "checkbeat.ico"
!define MUI_UNICON "checkbeat.ico"

;Version Information

  VIProductVersion "3.0.0.0"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "ProductName" "CheckBeat"
;  VIAddVersionKey /LANG=${LANG_ENGLISH} "Comments" "A test comment"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "CompanyName" "Zeta Centauri"
;  VIAddVersionKey /LANG=${LANG_ENGLISH} "LegalTrademarks" "Test Application is a trademark of Fake company"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "LegalCopyright" "Copyright 2006-2012 Zeta Centauri"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "FileDescription" "CheckBeat Installer"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "FileVersion" "3.0.0.0"
  VIAddVersionKey /LANG=${LANG_ENGLISH} "ProductVersion" "3.0.0.0"

;Interface Settings

  !define MUI_ABORTWARNING

;Pages

  !insertmacro MUI_PAGE_LICENSE "License.txt"
;  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
      !define MUI_FINISHPAGE_NOAUTOCLOSE
      !define MUI_FINISHPAGE_RUN
      !define MUI_FINISHPAGE_RUN_CHECKED
      !define MUI_FINISHPAGE_RUN_TEXT "Launch CheckBeat"
      !define MUI_FINISHPAGE_RUN_FUNCTION "LaunchProgram"
      !define MUI_FINISHPAGE_SHOWREADME ""
      !define MUI_FINISHPAGE_SHOWREADME_NOTCHECKED
      !define MUI_FINISHPAGE_SHOWREADME_TEXT "Create Desktop Shortcut"
      !define MUI_FINISHPAGE_SHOWREADME_FUNCTION finishpageaction
  !insertmacro MUI_PAGE_FINISH
  
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES

;Languages
 
  !insertmacro MUI_LANGUAGE "English"

; The stuff to install
Section "CheckBeat"

  SectionIn RO
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Put file there
  File "CheckBeat.exe"
  File "License.txt"
  File "checkbeat.ico"
  File "libsndfile-1.dll"
  File "c_hihat.wav"
  File "Closed-Hi-Hat-1.wav"
  File "Crash-Cymbal-1.wav"
  File "Dry-Kick.wav"
  File "hihat.wav"
  File "kick.wav"
  File "Kick-Drum-1.wav"
  File "Kick-Drum-2.wav"
  File "Open-Hi-Hat-1.wav"
  File "Pulse-Kick.wav"
  File "Ride-Cymbal-1.wav"
  File "Sine-Kick.wav"
  File "snare.wav"
  File "Snare-Drum-1.wav"
  File "Snare-Drum-2.wav"
  File "Thump-Kick.wav"
  File "Low-Tom-1.wav"
  File "Mid-Tom-1.wav"
  File "Hi-Tom-1.wav"

  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\CheckBeat "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CheckBeat" "DisplayName" "CheckBeat"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CheckBeat" "DisplayVersion" "3.0"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CheckBeat" "Publisher" "Zeta Centauri"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CheckBeat" "DisplayIcon" "$INSTDIR\checkbeat.ico"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CheckBeat" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CheckBeat" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CheckBeat" "NoRepair" 1
  WriteUninstaller "uninstall.exe"

SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\Zeta Centauri\CheckBeat"
  CreateShortCut "$SMPROGRAMS\Zeta Centauri\CheckBeat\CheckBeat.lnk" "$INSTDIR\CheckBeat.exe" "" "" 0
  ;CreateShortCut "$SMPROGRAMS\Zeta Centauri\CheckBeat\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  WriteINIStr "$SMPROGRAMS\Zeta Centauri\CheckBeat\CheckBeat Website.url" "InternetShortcut" "URL" "http://zetacentauri.com/software_checkbeat.htm"
  
SectionEnd

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\CheckBeat"
  DeleteRegKey HKLM SOFTWARE\CheckBeat

  ; Remove files and uninstaller
  Delete $INSTDIR\CheckBeat.exe
  Delete $INSTDIR\License.txt
  Delete $INSTDIR\checkbeat.ico
  Delete $INSTDIR\uninstall.exe
  Delete $INSTDIR\libsndfile-1.dll"
  Delete $INSTDIR\c_hihat.wav"
  Delete $INSTDIR\Closed-Hi-Hat-1.wav"
  Delete $INSTDIR\Crash-Cymbal-1.wav"
  Delete $INSTDIR\Dry-Kick.wav"
  Delete $INSTDIR\hihat.wav"
  Delete $INSTDIR\kick.wav"
  Delete $INSTDIR\Kick-Drum-1.wav"
  Delete $INSTDIR\Kick-Drum-2.wav"
  Delete $INSTDIR\Open-Hi-Hat-1.wav"
  Delete $INSTDIR\Pulse-Kick.wav"
  Delete $INSTDIR\Ride-Cymbal-1.wav"
  Delete $INSTDIR\Sine-Kick.wav"
  Delete $INSTDIR\snare.wav"
  Delete $INSTDIR\Snare-Drum-1.wav"
  Delete $INSTDIR\Snare-Drum-2.wav"
  Delete $INSTDIR\Thump-Kick.wav"
  Delete $INSTDIR\Low-Tom-1.wav"
  Delete $INSTDIR\Mid-Tom-1.wav"
  Delete $INSTDIR\Hi-Tom-1.wav"

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\Zeta Centauri\CheckBeat\*.*"
  Delete "$DESKTOP\CheckBeat.lnk"
  Delete "$SMPROGRAMS\Zeta Centauri\CheckBeat\CheckBeat Website.url"
  ;DeleteINISec "$SMPROGRAMS\Zeta Centauri\CheckBeat\CheckBeat Website.url" "InternetShortcut"

  ; Remove directories used
  RMDir "$SMPROGRAMS\Zeta Centauri\CheckBeat"
  RMDir "$SMPROGRAMS\Zeta Centauri"
  RMDir "$INSTDIR"


SectionEnd

Function LaunchProgram
  ExecShell "" "$SMPROGRAMS\Zeta Centauri\CheckBeat\CheckBeat.lnk"
FunctionEnd

Function finishpageaction
  CreateShortcut "$DESKTOP\CheckBeat.lnk" "$INSTDIR\CheckBeat.exe"
FunctionEnd