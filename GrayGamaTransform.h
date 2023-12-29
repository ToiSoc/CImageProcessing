#pragma once
#include "afxdialogex.h"


// GrayGamaTransform 对话框

class GrayGamaTransform : public CDialogEx
{
	DECLARE_DYNAMIC(GrayGamaTransform)

public:
	GrayGamaTransform(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GrayGamaTransform();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GrayGamaTransform };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_gama;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
