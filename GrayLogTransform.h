#pragma once
#include "afxdialogex.h"


// GrayLogTransform 对话框

class GrayLogTransform : public CDialogEx
{
	DECLARE_DYNAMIC(GrayLogTransform)

public:
	GrayLogTransform(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GrayLogTransform();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_log_c;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
