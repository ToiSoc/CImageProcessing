#pragma once
#include "afxdialogex.h"


// ThresholdSegment 对话框

class ThresholdSegment : public CDialogEx
{
	DECLARE_DYNAMIC(ThresholdSegment)

public:
	ThresholdSegment(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ThresholdSegment();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ThresholdSegment };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_threshold_size;
};
