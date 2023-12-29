// GaussianDialog.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "GaussianDialog.h"


// GaussianDialog 对话框

IMPLEMENT_DYNAMIC(GaussianDialog, CDialogEx)

GaussianDialog::GaussianDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GaussianDialog, pParent)
	, m_sigma(2.0)
{

}

GaussianDialog::~GaussianDialog()
{
}

void GaussianDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, m_3);
	DDX_Control(pDX, IDC_RADIO2, m_5);
	DDX_Control(pDX, IDC_RADIO3, m_7);
	DDX_Control(pDX, IDC_RADIO4, m_9);
	DDX_Text(pDX, IDC_EDIT1, m_sigma);
}


BEGIN_MESSAGE_MAP(GaussianDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &GaussianDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &GaussianDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// GaussianDialog 消息处理程序


void GaussianDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void GaussianDialog::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
