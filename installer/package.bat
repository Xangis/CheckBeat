echo This program runs the desktop app packager command to create a Windows 10 store package from an existing installer.
pause
DesktopAppConverter.exe -Installer "C:\Users\Xangis\code\CheckBeat\installer\CheckBeat3.1Setup.exe" -PackageName "CheckBeat" -Version 3.1.0.0 -Makeappx -Destination "C:\Users\Xangis\code\CheckBeat\installer" -InstallerArguments "/VERYSILENT" -Publisher "CN=Jason Champion" -Sign
Certutil -addStore TrustedPeople CheckBeat\auto-generated.cer



