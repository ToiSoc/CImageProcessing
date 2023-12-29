#pragma once
#include "afxdialogex.h"


// LinearTransform 对话框

class LinearTransform : public CDialogEx
{
	DECLARE_DYNAMIC(LinearTransform)

public:
	LinearTransform(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LinearTransform();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LinearTransform };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_ahpla;
	double m_beta;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton6();
};
