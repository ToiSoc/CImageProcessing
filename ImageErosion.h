#pragma once
#include "afxdialogex.h"


// ImageErosion 对话框

class ImageErosion : public CDialogEx
{
	DECLARE_DYNAMIC(ImageErosion)

public:
	ImageErosion(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ImageErosion();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ImageErosion };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_erosion;
};
