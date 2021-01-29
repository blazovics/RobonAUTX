; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "RobonAUT Controller"
#define MyAppVersion "1.2"
#define MyAppPublisher "BME AUT"
#define MyAppURL "https://www.aut.bme.hu"
#define MyAppExeName "RobonAUTXControl.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{DDCDFC6C-9369-4527-B513-AB01BEF46EC0}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\RobonAUTXControl
DisableProgramGroupPage=yes
; Remove the following line to run in administrative install mode (install for all users.)
PrivilegesRequired=lowest
PrivilegesRequiredOverridesAllowed=dialog
OutputBaseFilename=Controller-setup
SetupIconFile=D:\GoogleDrive\Pólórendelés\RobonAUT.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\AUT-Projects\RobonAUTX\build-RobonAUTXAll-Desktop_Qt_5_12_9_MinGW_64_bit-Release\RobonAUTXControl\release\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\AUT-Projects\RobonAUTX\build-RobonAUTXAll-Desktop_Qt_5_12_9_MinGW_64_bit-Release\RobonAUTXControl\release\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\AUT-Projects\RobonAUTX\build-RobonAUTXAll-Desktop_Qt_5_12_9_MinGW_64_bit-Release\RobonAUTXControl\release\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\AUT-Projects\RobonAUTX\build-RobonAUTXAll-Desktop_Qt_5_12_9_MinGW_64_bit-Release\RobonAUTXControl\release\Qt5Network.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\AUT-Projects\RobonAUTX\build-RobonAUTXAll-Desktop_Qt_5_12_9_MinGW_64_bit-Release\RobonAUTXControl\release\Qt5Qml.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\AUT-Projects\RobonAUTX\build-RobonAUTXAll-Desktop_Qt_5_12_9_MinGW_64_bit-Release\RobonAUTXControl\release\Qt5Quick.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\AUT-Projects\RobonAUTX\build-RobonAUTXAll-Desktop_Qt_5_12_9_MinGW_64_bit-Release\RobonAUTXControl\release\Qt5QuickTemplates2.dll"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

