#pragma once
#include "afxdialogex.h"


// ImageFilter 对话框

class ImageFilter : public CDialogEx
{
	DECLARE_DYNAMIC(ImageFilter)

public:
	ImageFilter(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ImageFilter();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MeanKerenlSize };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_kernel_size;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
