// DlgDDX.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
//2 �Ի�����
class CMyDlg:public CDialog
{
public:
	CMyDlg():CDialog(IDD_DIALOG1){}
	virtual BOOL OnInitDialog( );
	virtual void DoDataExchange( CDataExchange* pDX );
	virtual void OnOK();
protected:
	CButton m_btnOK;//��OK�󶨵ĳ�Ա����
    CString m_sText;//���ı���󶨵�ֵ���͵ĳ�Ա����
};
void CMyDlg::OnOK()
{
	//���û��ڿؼ��������ֵ���ݸ�����
	UpdateData(TRUE);

	MessageBox(m_sText);
	CDialog::OnOK();
}
void CMyDlg::DoDataExchange( CDataExchange* pDX )
{
	//����m_btnOK��OK��ť��
	DDX_Control(pDX,IDOK,m_btnOK);
	//ֵ���͵İ�
	DDX_Text(pDX,IDC_EDIT1,m_sText);
}
BOOL CMyDlg::OnInitDialog()
{
   if (!CDialog::OnInitDialog())
   {
		return FALSE;
   }
   //�ؼ��ĳ�ʼ������
   CWnd *pWnd=GetDlgItem(IDCANCEL);
   pWnd->EnableWindow(FALSE);
   //ʹ��DDX����OK��ť
   m_btnOK.MoveWindow(0,0,100,100);
   m_btnOK.SetWindowText("DDXOK");

   //ֵ���͵Ĳ���
   m_sText="Hello World";
   UpdateData(FALSE);
   return TRUE;
}
//1 Ӧ�ó�����
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	CMyDlg dlg;
	m_pMainWnd=&dlg;
	dlg.DoModal();
	return TRUE;
}



