// Dilation.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "Dilation.h"


// Dilation 对话框

IMPLEMENT_DYNAMIC(Dilation, CDialogEx)

Dilation::Dilation(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Dilation, pParent)
	, m_lambda_dilation(0)
{

}

Dilation::~Dilation()
{
}

void Dilation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_lambda_dilation);
}


BEGIN_MESSAGE_MAP(Dilation, CDialogEx)
END_MESSAGE_MAP()


// Dilation 消息处理程序
