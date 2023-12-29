#pragma once
#include "afxdialogex.h"


// CannyDetection 对话框

class CannyDetection : public CDialogEx
{
	DECLARE_DYNAMIC(CannyDetection)

public:
	CannyDetection(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CannyDetection();

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
};
