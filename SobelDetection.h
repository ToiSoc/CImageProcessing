#pragma once
#include "afxdialogex.h"


// SobelDetection 对话框

class SobelDetection : public CDialogEx
{
	DECLARE_DYNAMIC(SobelDetection)

public:
	SobelDetection(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SobelDetection();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KerbnlSize };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_kernel_size;
	afx_msg void OnBnClickedOk();
};
