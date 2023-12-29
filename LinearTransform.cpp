// LinearTransform.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "LinearTransform.h"


// LinearTransform 对话框

IMPLEMENT_DYNAMIC(LinearTransform, CDialogEx)

LinearTransform::LinearTransform(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LinearTransform, pParent)
	, m_ahpla(0)
	, m_beta(0)
{

}

LinearTransform::~LinearTransform()
{
}

void LinearTransform::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_InputEdit1, m_ahpla);
	DDX_Text(pDX, IDC_InputEdit2, m_beta);
}


BEGIN_MESSAGE_MAP(LinearTransform, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LinearTransform::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &LinearTransform::OnBnClickedButton6)
END_MESSAGE_MAP()


// LinearTransform 消息处理程序

void LinearTransform::OnBnClickedButton1()
{

	UpdateData(TRUE);
	CDialogEx::OnOK();
}


void LinearTransform::OnBnClickedButton6()
{
	return;
}


