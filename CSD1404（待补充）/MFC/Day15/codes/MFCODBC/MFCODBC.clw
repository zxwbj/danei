; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFCODBCDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCODBC.h"

ClassCount=3
Class1=CMFCODBCApp
Class2=CMFCODBCDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_MFCODBC_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX

[CLS:CMFCODBCApp]
Type=0
HeaderFile=MFCODBC.h
ImplementationFile=MFCODBC.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CMFCODBCDlg]
Type=0
HeaderFile=MFCODBCDlg.h
ImplementationFile=MFCODBCDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SHOW

[CLS:CAboutDlg]
Type=0
HeaderFile=MFCODBCDlg.h
ImplementationFile=MFCODBCDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFCODBC_DIALOG]
Type=1
Class=CMFCODBCDlg
ControlCount=2
Control1=IDC_LIST,SysListView32,1350631425
Control2=IDC_SHOW,button,1342242816

