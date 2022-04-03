#define MyAppName "DepotDownloader Console Tool"
#define MyAppVersion "1.5.0.0"
#define MyAppPublisher "qhy040404"
#define MyAppExeName "DepotDownloaderConsoleTool.exe"

[Setup]
AppId={{8E6BB262-3343-412F-9297-0632641E3C37}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
DisableWelcomePage=no
LicenseFile=J:\VSProjs\DepotDownloaderConsoleTool\LICENSE
OutputBaseFilename=DepotDownloader Console Tool Installer With .NET Installer
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
Source: "J:\VSProjs\DepotDownloaderConsoleTool\res\windowsdesktop-runtime-6.0.3-win-x64.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderConsoleTool\res\windowsdesktop-runtime-6.0.3-win-x86.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderConsoleTool\x64\Release\DotnetInstallHelper.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\config.bat"
Type: filesandordirs; Name: "{app}\depots"