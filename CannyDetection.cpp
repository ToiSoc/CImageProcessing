// CannyDetection.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "CannyDetection.h"


// CannyDetection 对话框

IMPLEMENT_DYNAMIC(CannyDetection, CDialogEx)

CannyDetection::CannyDetection(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CannyEdgeDetection, pParent)
	, m_threshold1(0)
	, m_threshold2(0)
{

}

CannyDetection::~CannyDetection()
{
}

void CannyDetection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_InputEdit1, m_threshold1);
	DDX_Text(pDX, IDC_InputEdit2, m_threshold2);
}


BEGIN_MESSAGE_MAP(CannyDetection, CDialogEx)
END_MESSAGE_MAP()


// CannyDetection 消息处理程序
