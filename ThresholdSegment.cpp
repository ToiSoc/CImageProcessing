// ThresholdSegment.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "ThresholdSegment.h"


// ThresholdSegment 对话框

IMPLEMENT_DYNAMIC(ThresholdSegment, CDialogEx)

ThresholdSegment::ThresholdSegment(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ThresholdSegment, pParent)
	, m_threshold_size(0)
{

}

ThresholdSegment::~ThresholdSegment()
{
}

void ThresholdSegment::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_threshold_size);
}


BEGIN_MESSAGE_MAP(ThresholdSegment, CDialogEx)
END_MESSAGE_MAP()


// ThresholdSegment 消息处理程序


