; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "DepotDownloader Console Tool"
#define MyAppVersion "1.0.0"
#define MyAppPublisher "qhy"
#define MyAppExeName "DepotDownloaderSimpleUI.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (若要生成新的 GUID，可在菜单中点击 "工具|生成 GUID"。)
AppId={{8E6BB262-3343-412F-9297-0632641E3C37}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
DisableWelcomePage=no
LicenseFile=J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\LICENSE
InfoBeforeFile=J:\VSProjs\DepotDownloaderSimpleUI\Setup\before.txt
; 以下行取消注释，以在非管理安装模式下运行（仅为当前用户安装）。
;PrivilegesRequired=lowest
OutputBaseFilename=DepotDownloader Console Tool Installer
SetupIconFile=J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\down.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern
WizardImageFile=J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\111.bmp    
WizardSmallImageFile=J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\000.bmp

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "J:\VSProjs\DepotDownloaderSimpleUI\Release\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\Release\DepotDownloaderSimpleUI.pdb"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.deps.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.dll.config"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.pdb"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\DepotDownloader.runtimeconfig.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\LICENSE"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\protobuf-net.Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\protobuf-net.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\README.md"; DestDir: "{app}"; Flags: ignoreversion
Source: "J:\VSProjs\DepotDownloaderSimpleUI\DepotDownloaderSimpleUI\Resources\SteamKit2.dll"; DestDir: "{app}"; Flags: ignoreversion
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

