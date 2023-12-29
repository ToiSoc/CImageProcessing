
// CImageProcessingDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "CImageProcessing.h"
#include "CImageProcessingDlg.h"
#include "afxdialogex.h"
#include "LinearTransform.h"
#include "GrayGamaTransform.h"
#include "GrayLogTransform.h"
#include "ImageErosion.h"
#include "Dilation.h"
#include "ThresholdSegment.h"
#include "SobelDetection.h"
#include "CannyEdgeDetection.h"
#include "ImageFilter.h"
#include "GaussianDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

String ResultFile = "result.png";
String EqualizeHistFile = "equalizeHist.png";

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP();

public:

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


// CCImageProcessingDlg 对话框



CCImageProcessingDlg::CCImageProcessingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CIMAGEPROCESSING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCImageProcessingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_11, m_p1);
	DDX_Control(pDX, IDC_22, m_p2);
}

BEGIN_MESSAGE_MAP(CCImageProcessingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCImageProcessingDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCImageProcessingDlg::OnBnClickedButton3)
	ON_COMMAND(ID_32771, &CCImageProcessingDlg::On_RGB_2_Gray)
	ON_BN_CLICKED(IDC_BUTTON4, &CCImageProcessingDlg::OnBnClickedButton4)
	ON_COMMAND(ID_32773, &CCImageProcessingDlg::OnEqualizeHist)
	ON_BN_CLICKED(IDC_BUTTON5, &CCImageProcessingDlg::OnBnClickedButton5)
	ON_COMMAND(ID_32775, &CCImageProcessingDlg::On_GrayScaleLinearTransform)
	ON_COMMAND(ID_32777, &CCImageProcessingDlg::On_LogTransform)
	ON_COMMAND(ID_32778, &CCImageProcessingDlg::On_GrayGamaTransform)
	ON_COMMAND(ID_32779, &CCImageProcessingDlg::On_ImageErosion)
	ON_COMMAND(ID_32780, &CCImageProcessingDlg::On_Dilation)
	ON_COMMAND(ID_32784, &CCImageProcessingDlg::On_ThresholdSegment)
	ON_COMMAND(ID_32785, &CCImageProcessingDlg::On_AdaptiveThresholdSegment)
	ON_COMMAND(ID_32782, &CCImageProcessingDlg::On_RegionGrowingThreshold)
	ON_COMMAND(ID_32786, &CCImageProcessingDlg::On_SobelEdgeDetection)
	ON_COMMAND(ID_32787, &CCImageProcessingDlg::On_CannyDetection)
	ON_COMMAND(ID_32788, &CCImageProcessingDlg::On_MeanFilter)
	ON_COMMAND(ID_32789, &CCImageProcessingDlg::On_MedianFilter)
	ON_COMMAND(ID_32790, &CCImageProcessingDlg::On_GaussianFilter)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCImageProcessingDlg 消息处理程序

BOOL CCImageProcessingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCImageProcessingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCImageProcessingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCImageProcessingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}







void CCImageProcessingDlg::OnBnClickedButton1()
{

	CString fileName;
	TCHAR szFilter[] = _T("JPEG文件(*.jpg)|*.jpg|GIF文件(*.gif)|*.gif|bmp文件(*.bmp)|*.bmp||");
	CFileDialog fileDig(TRUE, _T("jpg"), NULL, 0, szFilter, this);

	if (fileDig.DoModal() != IDOK)	//为点击确认按钮
	{
		return;
	}
	fileName = fileDig.GetPathName();

	CImage image;
	image.Load(fileName);
	CRect rectControl;
	m_p1.GetClientRect(rectControl);
	CDC* pCdc = m_p1.GetDC();

	image.Draw(pCdc->m_hDC, rectControl);
	image.Destroy();	//销毁图片
	m_p1.ReleaseDC(pCdc);
	src = imread(fileName.GetBuffer(), 1);

}


void CCImageProcessingDlg::ShowDst(CStatic* p,const char fileName[])
{
	CImage image;
	image.Load(TEXT(fileName));
	CRect rectControl;
	p->GetClientRect(rectControl);
	CDC* pCdc = p->GetDC();

	image.Draw(pCdc->m_hDC, rectControl);
	image.Destroy();	//销毁图片
	p->ReleaseDC(pCdc);
}

bool CCImageProcessingDlg::CheckSrcIsNull(Mat src)
{
	return src.empty() ? true : false;
}


void CCImageProcessingDlg::On_RGB_2_Gray()
{
	// TODO: 在此添加命令处理程序代码
	if (src.empty())
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	dst = image_process.RGB_2_Gray(src);
	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}



void CCImageProcessingDlg::OnBnClickedButton3()
{
	if (src.empty())
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	image_process.Show_Histogram(src);
}




void CCImageProcessingDlg::OnBnClickedButton4()
{
	int result = MessageBoxW(NULL, L"确定要退出吗？", L"标题", MB_OK | MB_OKCANCEL | MB_ICONEXCLAMATION);
	switch (result)
	{
		case IDOK:
			exit(0);
			break;

		case IDCANCEL:
			break;
	}
}


void CCImageProcessingDlg::OnEqualizeHist()
{
	if (src.empty())
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	dst = image_process.EqualizeHist(src);
	imwrite(EqualizeHistFile, dst);
	ShowDst(&m_p2, EqualizeHistFile.c_str());
}



void CCImageProcessingDlg::OnBnClickedButton5()
{
	dst = imread(EqualizeHistFile, 1);
	if (dst.empty())
	{
		MessageBox("请先生成均衡图片!!!");
		return;
	}
	image_process.Show_Histogram(dst);
}


void CCImageProcessingDlg::On_GrayScaleLinearTransform()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}


	double alpha = 1.5;
	double beta = 30;

	LinearTransform lt_dig;
	lt_dig.m_ahpla = 1.5;
	lt_dig.m_beta = 30;
	if (lt_dig.DoModal() == IDOK)
	{
		alpha = lt_dig.m_ahpla;
		beta = lt_dig.m_beta;
	}

	dst = image_process.GrayScaleLinearTransform(src,alpha,beta);
	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}



void CCImageProcessingDlg::On_LogTransform()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}


	double c = 40;
	
	GrayLogTransform grayLogTransform;
	grayLogTransform.m_log_c = 2.5;

	if (grayLogTransform.DoModal() == IDOK)
	{
		c = grayLogTransform.m_log_c;
	}

	dst = image_process.GrayLogTransform(src,c);

	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}


void CCImageProcessingDlg::On_GrayGamaTransform()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	double gama = 0.5;
	GrayGamaTransform grayGamaTransform;
	grayGamaTransform.m_gama = 0.5;
	if (grayGamaTransform.DoModal() == IDOK)
	{
		gama = grayGamaTransform.m_gama;
	}

	dst = image_process.GrayScaleGamaTransform(src, gama);

	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}


void CCImageProcessingDlg::On_ImageErosion()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	double erosionSize = 3;
	ImageErosion imageErosion;
	imageErosion.m_erosion = 3;
	if (imageErosion.DoModal() == IDOK)
	{
		erosionSize = imageErosion.m_erosion;
	}
	dst = image_process.ImageErosion(src, erosionSize);

	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}



void CCImageProcessingDlg::On_Dilation()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}


	int dilationSize = 3;

	Dilation dilation;
	dilation.m_lambda_dilation = 3;
	if (dilation.DoModal() == IDOK)
	{
		dilationSize = dilation.m_lambda_dilation;
	}

	dst = image_process.ImageDilation(src, dilationSize);

	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}


void CCImageProcessingDlg::On_ThresholdSegment()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	double thresholdSize = 128;

	ThresholdSegment thresholdSegment;
	thresholdSegment.m_threshold_size = 128;

	if (thresholdSegment.DoModal() == IDOK)
	{
		thresholdSize = thresholdSegment.m_threshold_size;
	}

	dst = image_process.ImageThresholdSegmentation(src, thresholdSize);

	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}


void CCImageProcessingDlg::On_AdaptiveThresholdSegment()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	//阈值分割参数
	double blockSize = 11;
	double subtractValue = 10;
	dst = image_process.ImageAdaptiveThresholdSegmentation(src, blockSize, subtractValue);
	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}





void CCImageProcessingDlg::On_RegionGrowingThreshold()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	//区域生长分割参数
	int seedX = 100;
	int seedY = 100;		
	int thresholdSize = 50;		//阈值

	dst = image_process.RegionGrowingSegmentation(src, seedX, seedY, thresholdSize);
	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());

}

int CheckValue(int num)
{
	while (num && num % 3 == 0)
	{
		num /= 3;
	}
	return num;
}

void CCImageProcessingDlg::On_SobelEdgeDetection()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	//定义Sobel核大小
	int kernelSize = 3;

	SobelDetection sobelDetection;
	sobelDetection.m_kernel_size = 3;

	if (sobelDetection.DoModal() == IDOK)
	{
		if (CheckValue(sobelDetection.m_kernel_size) != 1)
		{
			MessageBox("请输入3的幂，已重置为3！");
		}
		else
		{
			kernelSize = sobelDetection.m_kernel_size;
		}
	}

	dst = image_process.SobelEdgeDetection(src,kernelSize);
	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());

}



void CCImageProcessingDlg::On_CannyDetection()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}
	
	double threshold1 = 50;	//低阈值
	double threshold2 = 150;	//高阈值
	
	CannyEdgeDetection cannyDetection;
	cannyDetection.m_threshold1 = threshold1;
	cannyDetection.m_threshold2 = threshold2;
	
	if (cannyDetection.DoModal() == IDOK)
	{
		threshold1 = cannyDetection.m_threshold1;
		threshold2 = cannyDetection.m_threshold2;
	}
	
	dst = image_process.CannyEdgeDetection(src, threshold1, threshold2);
	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}


void CCImageProcessingDlg::On_MeanFilter()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	int kernelSize = 3;

	ImageFilter imageFilter;
	imageFilter.m_kernel_size = 3;

	if (imageFilter.DoModal() == IDOK && imageFilter.m_kernel_size <= 20)
	{

		kernelSize = imageFilter.m_kernel_size;
	}


	dst = image_process.MeanFilter(src,kernelSize);
	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}


void CCImageProcessingDlg::On_MedianFilter()
{
	
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	int kernelSize = 3;

	ImageFilter imageFilter;
	imageFilter.m_kernel_size = 3;

	if (imageFilter.DoModal() == IDOK)
	{
		if (CheckValue(imageFilter.m_kernel_size) != 1)
		{
			MessageBox("请输入3的幂，已重置为3！");
		}
		else
		{
			kernelSize = imageFilter.m_kernel_size;
		}
	}

	dst = image_process.MedianFilter(src, kernelSize);
	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}


void CCImageProcessingDlg::On_GaussianFilter()
{
	if (CheckSrcIsNull(src))
	{
		MessageBox("请先导入图片!!!");
		return;
	}

	int kernelSize = 5;
	double sigma = 2.0;

	GaussianDialog gaussianFilter;

	if (gaussianFilter.DoModal() == IDOK)
	{
		if (BST_CHECKED == gaussianFilter.m_3.GetCheck())
		{
			kernelSize = 3;
		}
		else if (BST_CHECKED == gaussianFilter.m_5.GetCheck())
		{
			kernelSize = 5;
		}
		else if (BST_CHECKED == gaussianFilter.m_7.GetCheck())
		{
			kernelSize = 7;
		}
		else if (BST_CHECKED == gaussianFilter.m_9.GetCheck())
		{
			kernelSize = 9;
		}
		sigma = gaussianFilter.m_sigma;
	}



	dst = image_process.GaussianFilter(src, kernelSize, sigma);
	imwrite(ResultFile, dst);
	ShowDst(&m_p2, ResultFile.c_str());
}
