#define MyAppName "DepotDownloader Console Tool"
#define MyAppVersion "1.4.1"
#define MyAppPublisher "qhy"
#define MyAppExeName "DepotDownloaderSimpleUI.exe"

[Setup]
AppId={{9BCE7A22-4E14-483F-A41D-FF1CD23E6B02}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
DisableWelcomePage=no
LicenseFile=J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\LICENSE
InfoBeforeFile=J:\VSProjs\DepotDownloaderSimpleUI\Setup\before.txt
OutputBaseFilename=DepotDownloader Console Tool Installer Without .NET Installer
SetupIconFile=J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\down.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern
WizardImageFile=J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\111.bmp    
WizardSmallImageFile=J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\000.bmp

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"
Name: "en"; MessagesFile: "compiler:Languages\English.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"

[Files]
Source: "J:\VSProjs\DepotDownloaderSimpleUI\Release\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\Release\DepotDownloaderSimpleUI.pdb"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.deps.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.dll.config"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.pdb"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.runtimeconfig.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\protobuf-net.Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\protobuf-net.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\SteamKit2.dll"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\config.bat"
Type: filesandordirs; Name: "{app}\depots"