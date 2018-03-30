// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bkres/res.h"
#include "MainDlg.h"

#ifdef _DEBUG
#pragma comment(lib,"../Debug/tinyxml.lib")
#else
#pragma comment(lib,"../Release/tinyxml.lib")
#endif // _DEBUG

CMainDlg::CMainDlg():CBkDialogImpl<CMainDlg>(IDR_BK_MAIN_DIALOG) // ��������ؽ�����
{
	// ���� Load xx ������Ǳ���ģ�����Ƥ����������ʾ
	BkString::Load(IDR_BK_STRING_DEF); // �����ַ���
	BkFontPool::SetDefaultFont(BkString::Get(IDS_APP_FONT), -12); // ��������
	BkSkin::LoadSkins(IDR_BK_SKIN_DEF); // ����Ƥ��
	BkStyle::LoadStyles(IDR_BK_STYLE_DEF); // ���ط��
}

CMainDlg::~CMainDlg()
{

}

void CMainDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	OutputDebugString(_T("��굯��\n"));
}

void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	OutputDebugString(_T("��갴��\n"));
}


void CMainDlg::OnBkBtnMax()  
{  
	if (WS_MAXIMIZE == (GetStyle() & WS_MAXIMIZE))  
	{  
		SendMessage(WM_SYSCOMMAND, SC_RESTORE | HTCAPTION, 0);  
	}  
	else  
	{  
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE | HTCAPTION, 0);  
	}  
}  

void CMainDlg::OnBkBtnMin()  
{  
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE | HTCAPTION, 0);  
}  

void CMainDlg::OnBkBtnClose()  
{  
	DestroyWindow();  
}  

void CMainDlg::OnDestroy()
{
	OutputDebugStringA(__FUNCTION__);
	PostQuitMessage(0);  
}