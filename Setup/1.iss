; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "DepotDownloader Console Tool"
#define MyAppVersion "1.0.0"
#define MyAppPublisher "qhy"
#define MyAppExeName "DepotDownloaderSimpleUI.exe"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (��Ҫ�����µ� GUID�����ڲ˵��е�� "����|���� GUID"��)
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
; ������ȡ��ע�ͣ����ڷǹ���װģʽ�����У���Ϊ��ǰ�û���װ����
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
; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

