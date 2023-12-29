#pragma once
#include "afxdialogex.h"


// GaussianDialog 对话框

class GaussianDialog : public CDialogEx
{
	DECLARE_DYNAMIC(GaussianDialog)

public:
	GaussianDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GaussianDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GaussianDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CButton m_3;
	CButton m_5;
	CButton m_7;
	CButton m_9;
	double m_sigma;
};
