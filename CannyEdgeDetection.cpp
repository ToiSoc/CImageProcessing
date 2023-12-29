// CannyEdgeDetection.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "CannyEdgeDetection.h"


// CannyEdgeDetection 对话框

IMPLEMENT_DYNAMIC(CannyEdgeDetection, CDialogEx)

CannyEdgeDetection::CannyEdgeDetection(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CannyEdgeDetection, pParent)
	, m_threshold1(0)
	, m_threshold2(0)
{

}

CannyEdgeDetection::~CannyEdgeDetection()
{
}

void CannyEdgeDetection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_InputEdit1, m_threshold1);
	DDX_Text(pDX, IDC_InputEdit2, m_threshold2);
}


BEGIN_MESSAGE_MAP(CannyEdgeDetection, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CannyEdgeDetection::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CannyEdgeDetection::OnBnClickedButton6)
END_MESSAGE_MAP()


// CannyEdgeDetection 消息处理程序


void CannyEdgeDetection::OnBnClickedButton1()
{
	CDialogEx::OnOK();
}



void CannyEdgeDetection::OnBnClickedButton6()
{
	CDialogEx::OnCancel();
}
