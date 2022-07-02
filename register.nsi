;NSIS Register for Scriptable User.

!include "WinMessages.nsh"

Name "Scriptable User Reg register"
OutFile "SURegister.exe"
RequestExecutionLevel user
Unicode True
SilentInstall silent

Section "Add to PATH"
  ReadRegStr $0 HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" "Path"
  WriteRegExpandStr HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment" "Path" "$0;$EXEDIR"
  SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment"
SectionEnd
