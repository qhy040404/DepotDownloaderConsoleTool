#define MyAppName "DepotDownloader Console Tool"
#define MyAppVersion "1.4.3"
#define MyAppPublisher "qhy040404"
#define MyAppExeName "DepotDownloaderSimpleUI.exe"

[Setup]
AppId={{9BCE7A22-4E14-483F-A41D-FF1CD23E6B02}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
DisableWelcomePage=no
LicenseFile=J:\VSProjs\DepotDownloaderConsoleTool\LICENSE
InfoBeforeFile=J:\VSProjs\DepotDownloaderConsoleTool\setup\before.txt
OutputBaseFilename=DepotDownloader Console Tool Installer Without .NET Installer
SetupIconFile=J:\VSProjs\DepotDownloaderConsoleTool\res\icon.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern
WizardImageFile=J:\VSProjs\DepotDownloaderConsoleTool\setup\res\left.bmp
WizardSmallImageFile=J:\VSProjs\DepotDownloaderConsoleTool\setup\res\round.bmp

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"
Name: "en"; MessagesFile: "compiler:Languages\English.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"

[Files]
Source: "J:\VSProjs\DepotDownloaderConsoleTool\x64\Release\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\DepotDownloader.deps.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\DepotDownloader.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\DepotDownloader.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\DepotDownloader.runtimeconfig.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\protobuf-net.Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\protobuf-net.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSRepos\DepotDownloader\DepotDownloader\bin\Release\net6.0\SteamKit2.dll"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\config.bat"
Type: filesandordirs; Name: "{app}\depots"