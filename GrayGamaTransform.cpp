// GrayGamaTransform.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "GrayGamaTransform.h"


// GrayGamaTransform 对话框

IMPLEMENT_DYNAMIC(GrayGamaTransform, CDialogEx)

GrayGamaTransform::GrayGamaTransform(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GrayGamaTransform, pParent)
	, m_gama(0)
{

}

GrayGamaTransform::~GrayGamaTransform()
{
}

void GrayGamaTransform::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_gama);
}


BEGIN_MESSAGE_MAP(GrayGamaTransform, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &GrayGamaTransform::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &GrayGamaTransform::OnBnClickedOk)
END_MESSAGE_MAP()


// GrayGamaTransform 消息处理程序


void GrayGamaTransform::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void GrayGamaTransform::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
