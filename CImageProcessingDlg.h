// CImageProcessingDlg.h: 头文件
//


#include "ImageProcess.h"
#pragma once


// CCImageProcessingDlg 对话框
class CCImageProcessingDlg : public CDialogEx
{
// 构造
public:
	CCImageProcessingDlg(CWnd* pParent = nullptr);	// 标准构造函数

	CStatic m_p1;
	CStatic m_p2;


	//对上传的图像加个标度51
	Mat src;	//原始图像
	Mat dst;	//处理后的图像


	ImageProcess image_process;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void On_RGB_2_Gray();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CIMAGEPROCESSING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void ShowDst(CStatic* p,const char fileName[]);	//显示图片
	bool CheckSrcIsNull(Mat src);	//检查是否导入土拍你

	afx_msg void OnBnClickedButton4();
	afx_msg void OnEqualizeHist();
	afx_msg void OnBnClickedButton5();
	afx_msg void On_GrayScaleLinearTransform();
	afx_msg void On_LogTransform();
	afx_msg void On_GrayGamaTransform();
	afx_msg void On_ImageErosion();
	afx_msg void On_Dilation();
	afx_msg void On_ThresholdSegment();
	afx_msg void On_AdaptiveThresholdSegment();
	afx_msg void On_RegionGrowingThreshold();
	afx_msg void On_SobelEdgeDetection();
	afx_msg void On_CannyEdgeDetection();
	afx_msg void On_CannyDetection();
	afx_msg void On_MeanFilter();
	afx_msg void On_MedianFilter();
	afx_msg void On_GaussianFilter();
};



