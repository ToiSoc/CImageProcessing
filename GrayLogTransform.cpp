// GrayLogTransform.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "GrayLogTransform.h"


// GrayLogTransform 对话框

IMPLEMENT_DYNAMIC(GrayLogTransform, CDialogEx)

GrayLogTransform::GrayLogTransform(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_log_c(0)
{

}

GrayLogTransform::~GrayLogTransform()
{
}

void GrayLogTransform::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_log_c);
}


BEGIN_MESSAGE_MAP(GrayLogTransform, CDialogEx)
	ON_BN_CLICKED(IDOK, &GrayLogTransform::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &GrayLogTransform::OnBnClickedCancel)
END_MESSAGE_MAP()


// GrayLogTransform 消息处理程序


void GrayLogTransform::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void GrayLogTransform::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
