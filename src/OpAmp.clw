; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COpAmpView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OpAmp.h"
LastPage=0

ClassCount=9
Class1=COpAmpApp
Class2=COpAmpDoc
Class3=COpAmpView
Class4=CMainFrame

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDD_NEW
Class5=CAboutDlg
Resource3=IDD_OPAMP_FORM
Resource4=IDD_ABOUTBOX
Resource5=IDD_SAVE
Class6=CNewOpAmp
Class7=CLoadOpAmp
Class8=CDb
Class9=CSaveOpAmp
Resource6=IDD_LOAD

[CLS:COpAmpApp]
Type=0
HeaderFile=OpAmp.h
ImplementationFile=OpAmp.cpp
Filter=N
LastObject=COpAmpApp

[CLS:COpAmpDoc]
Type=0
HeaderFile=OpAmpDoc.h
ImplementationFile=OpAmpDoc.cpp
Filter=N
LastObject=COpAmpDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:COpAmpView]
Type=0
HeaderFile=OpAmpView.h
ImplementationFile=OpAmpView.cpp
Filter=D
LastObject=COMBO
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=OpAmp.cpp
ImplementationFile=OpAmp.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_APP_ABOUT
CommandCount=7

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_OPAMP_FORM]
Type=1
Class=COpAmpView
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=COMBO,combobox,1344340227
Control3=VAL,edit,1350631552
Control4=SET,button,1342242817
Control5=GAIN,static,1342312960

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_APP_ABOUT
CommandCount=5

[DLG:IDD_NEW]
Type=1
Class=CNewOpAmp
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=INPUTR,edit,1350639744
Control3=IDC_STATIC,static,1342308352
Control4=OUTPUTR,edit,1350639744
Control5=IDC_STATIC,static,1342308352
Control6=GAIN,edit,1350639744
Control7=IDC_STATIC,static,1342308352
Control8=TYPE,combobox,1344340227
Control9=REVERSE,button,1342242819
Control10=IDC_STATIC,static,1342308352
Control11=MAX,edit,1350639744
Control12=IDC_STATIC,static,1342308352
Control13=MIN,edit,1350639744
Control14=IDOK,button,1342242816
Control15=IDCANCEL,button,1342242816

[DLG:IDD_SAVE]
Type=1
Class=CSaveOpAmp
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=DESC,edit,1350631556

[DLG:IDD_LOAD]
Type=1
Class=CLoadOpAmp
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=LIST,SysListView32,1350631429

[CLS:CNewOpAmp]
Type=0
HeaderFile=NewOpAmp.h
ImplementationFile=NewOpAmp.cpp
BaseClass=CDialog
Filter=D
LastObject=CNewOpAmp
VirtualFilter=dWC

[CLS:CLoadOpAmp]
Type=0
HeaderFile=LoadOpAmp.h
ImplementationFile=LoadOpAmp.cpp
BaseClass=CDialog
Filter=D
LastObject=LIST
VirtualFilter=dWC

[CLS:CDb]
Type=0
HeaderFile=Db.h
ImplementationFile=Db.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x
LastObject=CDb

[DB:CDb]
DB=1
DBType=DAO
ColumnCount=8
Column1=[index], 4, 4
Column2=[name], 12, 50
Column3=[desc], 12, 50
Column4=[Ri], 4, 4
Column5=[Ro], 4, 4
Column6=[Gain], 12, 50
Column7=[amount], 5, 2
Column8=[resistors], -1, 0

[CLS:CSaveOpAmp]
Type=0
HeaderFile=SaveOpAmp.h
ImplementationFile=SaveOpAmp.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSaveOpAmp

