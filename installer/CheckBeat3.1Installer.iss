; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "CheckBeat"
#define MyAppVersion "3.1"
#define MyAppPublisher "Zeta Centauri"
#define MyAppURL "http://zetacentauri.com/software_checkbeat.htm"
#define MyAppExeName "CheckBeat.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{82FE27C8-E07C-4B74-81E0-16F0B5FE384B}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\Zeta Centauri\CheckBeat
DefaultGroupName=Zeta Centauri\CheckBeat
DisableProgramGroupPage=yes
LicenseFile=C:\Users\Xangis\code\CheckBeat\Release\License.txt
OutputDir=C:\Users\Xangis\code\CheckBeat\Installer
OutputBaseFilename=CheckBeat3.1Setup
SetupIconFile=C:\Users\Xangis\code\CheckBeat\checkbeat.ico
UninstallDisplayIcon={app}\checkbeat.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "C:\Users\Xangis\code\CheckBeat\Release\CheckBeat.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\SDL2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\SDL2_mixer.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\checkbeat.ico"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\c_hihat.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Closed-Hi-Hat-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Crash-Cymbal-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Dry-Kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\hihat.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Kick-Drum-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Kick-Drum-2.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Open-Hi-Hat-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Pulse-Kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Ride-Cymbal-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Sine-Kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\snare.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Snare-Drum-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Snare-Drum-2.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Thump-Kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Low-Tom-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Mid-Tom-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Xangis\code\CheckBeat\Release\Hi-Tom-1.wav"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent
