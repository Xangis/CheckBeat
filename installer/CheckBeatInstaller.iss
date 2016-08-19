; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "CheckBeat"
#define MyAppVersion "3.0"
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
LicenseFile=K:\src\CheckBeat\Release\License.txt
OutputDir=K:\src\CheckBeat\Release
OutputBaseFilename=CheckBeat3Setup
SetupIconFile=K:\src\CheckBeat\Release\checkbeat.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "K:\src\CheckBeat\Release\CheckBeat.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\libsndfile-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\c_hihat.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Closed-Hi-Hat-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Crash-Cymbal-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Dry-Kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\hihat.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Kick-Drum-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Kick-Drum-2.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Open-Hi-Hat-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Pulse-Kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Ride-Cymbal-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Sine-Kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\snare.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Snare-Drum-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Snare-Drum-2.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Thump-Kick.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Low-Tom-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Mid-Tom-1.wav"; DestDir: "{app}"; Flags: ignoreversion
Source: "K:\src\CheckBeat\Release\Hi-Tom-1.wav"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent
