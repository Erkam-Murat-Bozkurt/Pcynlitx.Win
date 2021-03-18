; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "Mingw64"
#define MyAppVersion "1.0"
#define MyAppPublisher "Erkam Murat Bozkurt M.Sc Control Systems Engineering"
#define MyAppURL "https://www.pcynlitx.tech/"


[Setup]

AppId={{FFD8A5A8-BDC7-4A18-B763-EEEECD5732F6}
AppName=Mingw64
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
DefaultDirName={autopf}\Mingw64
DisableDirPage=yes
DisableProgramGroupPage=yes
LicenseFile=D:\My_Mingw64_Installer\LICENSE.txt
OutputDir=D:\My_Mingw64_Installer
OutputBaseFilename=Mingw64.Setup
SetupIconFile=D:\My_Mingw64_Installer\icon.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
Source: "D:\My_Mingw64_Installer\7z\*"; DestDir: "{autopf}\Mingw64\7z"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\My_Mingw64_Installer\mingw64.7z"; DestDir: "{autopf}\Mingw64\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\My_Mingw64_Installer\LICENSE.txt"; DestDir: "{autopf}\Mingw64"; Flags: ignoreversion
Source: "D:\My_Mingw64_Installer\extract_mingw64.exe"; DestDir: "{autopf}\Mingw64";  Flags: ignoreversion

[UninstallDelete]
Type: filesandordirs; Name: "{autopf}\Mingw64\mingw64"

[Run]
Filename: "{autopf}\Mingw64\extract_mingw64.exe"; WorkingDir: "{autopf}\Mingw64"; Flags:runascurrentuser  runhidden; \
BeforeInstall: UpdateProgressbar(75); AfterInstall: UpdateProgressBar(90);

[Code]
procedure SetProgressBarMax(Ratio: Integer);
begin
  WizardForm.ProgressGauge.Max := WizardForm.ProgressGauge.Max * Ratio;
end;

procedure UpdateProgressBar(Position: Integer);
begin
  WizardForm.ProgressGauge.Position := Position * WizardForm.ProgressGauge.Max div 100;
end;
 

