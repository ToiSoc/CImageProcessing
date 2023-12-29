// ImageFilter.cpp: 实现文件
//

#include "pch.h"
#include "CImageProcessing.h"
#include "afxdialogex.h"
#include "ImageFilter.h"


// ImageFilter 对话框

IMPLEMENT_DYNAMIC(ImageFilter, CDialogEx)

ImageFilter::ImageFilter(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MeanKerenlSize, pParent)
	, m_kernel_size(0)
{

}

ImageFilter::~ImageFilter()
{
}

void ImageFilter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_kernel_size);
}


BEGIN_MESSAGE_MAP(ImageFilter, CDialogEx)
	ON_BN_CLICKED(IDOK, &ImageFilter::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ImageFilter::OnBnClickedCancel)
END_MESSAGE_MAP()


// ImageFilter 消息处理程序


void ImageFilter::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void ImageFilter::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
