#pragma once
#include "afxdialogex.h"


// Dilation 对话框

class Dilation : public CDialogEx
{
	DECLARE_DYNAMIC(Dilation)

public:
	Dilation(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dilation();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dilation };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_lambda_dilation;
};
