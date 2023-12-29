// ImageErosion.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "ImageErosion.h"


// ImageErosion 对话框

IMPLEMENT_DYNAMIC(ImageErosion, CDialogEx)

ImageErosion::ImageErosion(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ImageErosion, pParent)
	, m_erosion(0)
{

}

ImageErosion::~ImageErosion()
{
}

void ImageErosion::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_erosion);
}


BEGIN_MESSAGE_MAP(ImageErosion, CDialogEx)
END_MESSAGE_MAP()


// ImageErosion 消息处理程序
