// SobelDetection.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "SobelDetection.h"


// SobelDetection 对话框

IMPLEMENT_DYNAMIC(SobelDetection, CDialogEx)

SobelDetection::SobelDetection(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KerbnlSize, pParent)
	, m_kernel_size(0)
{

}

SobelDetection::~SobelDetection()
{
}

void SobelDetection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kernel_size);
}


BEGIN_MESSAGE_MAP(SobelDetection, CDialogEx)
	ON_BN_CLICKED(IDOK, &SobelDetection::OnBnClickedOk)
END_MESSAGE_MAP()


// SobelDetection 消息处理程序


void SobelDetection::OnBnClickedOk()
{

	CDialogEx::OnOK();
}


