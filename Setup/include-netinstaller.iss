#define MyAppName "DepotDownloader Console Tool"
#define MyAppVersion "1.4.1"
#define MyAppPublisher "qhy"
#define MyAppExeName "DepotDownloaderSimpleUI.exe"

[Setup]
AppId={{8E6BB262-3343-412F-9297-0632641E3C37}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
DisableWelcomePage=no
LicenseFile=J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\LICENSE
OutputBaseFilename=DepotDownloader Console Tool Installer With .NET Installer
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
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\DepotDownloader.deps.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\DepotDownloader.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\DepotDownloader.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\DepotDownloader.runtimeconfig.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\protobuf-net.Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\protobuf-net.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\SteamKit2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\windowsdesktop-runtime-6.0.3-win-x64.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\windowsdesktop-runtime-6.0.3-win-x86.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[UninstallDelete]
Type: files; Name: "{app}\config.bat"
Type: filesandordirs; Name: "{app}\depots"