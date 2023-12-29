#pragma once
#include "afxdialogex.h"


// CannyEdgeDetection 对话框

class CannyEdgeDetection : public CDialogEx
{
	DECLARE_DYNAMIC(CannyEdgeDetection)

public:
	CannyEdgeDetection(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CannyEdgeDetection();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CannyEdgeDetection };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_threshold1;
	double m_threshold2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton6();
};
