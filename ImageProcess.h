#pragma once
class ImageProcess
{

public:
	void Show_Histogram(Mat src);												//显示灰度直方图


	/**
		* 灰度处理
	*/
	Mat RGB_2_Gray(Mat src);													//图片转灰度
	Mat EqualizeHist(Mat src);													//直方图均衡化
	Mat GrayScaleLinearTransform(Mat InputImage, double alpha, double beta);	//线性灰度变换
	Mat GrayLogTransform(Mat inputImage, double c);								//灰度对数变换
	Mat GrayScaleGamaTransform(Mat inputImage, double gama);					//灰度 γ 变换

	/**
		* 形态学处理
	*/
	Mat ImageErosion(Mat inputImage, int erosionSize);			//腐蚀
	Mat ImageDilation(Mat inputImage, int dilationSize);		//膨胀

	/**
		* 图像处理
	*/
	Mat ImageThresholdSegmentation(Mat inputImage, int thresholdSize);							//固定阈值
	Mat ImageAdaptiveThresholdSegmentation(Mat inputImage, int blockSize, int subtractValue);	//自适应阈值
	Mat RegionGrowingSegmentation(Mat inputImage, int seedX, int seedY, int thresholdSize);		//区域生长分割
	Mat SobelEdgeDetection(Mat inputImage, int kernelSize);										//Sobel算法
	Mat CannyEdgeDetection(Mat inputImage, double threshold1, double threshold2);				//Canny算法

	/**
		* 图像滤波
	*/
	Mat MeanFilter(Mat inputImage, int kernelSize);												//均值滤波
	Mat MedianFilter(Mat inputImage, int kernelSize);											//中值滤波
	Mat GaussianFilter(Mat inputImage, int kernelSize, double sigma);							//高斯滤波
};

