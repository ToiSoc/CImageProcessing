#include "pch.h"
#include "ImageProcess.h"

Mat ImageProcess::RGB_2_Gray(Mat src)
{
    Mat result;
    cvtColor(src, result, cv::COLOR_RGB2GRAY);
    return result;
}

bool CheckSrcIsNull(Mat src)
{
	return src.empty() ? true : false;
}

void ImageProcess::Show_Histogram(Mat src)
{
	Mat image_gray, hist;   //定义输入图像，灰度图像, 直方图
		
	if (src.empty())
	{
		MessageBoxA(NULL, "请先导入图片!!!", "警告", MB_OK);
		return;
	}

	cvtColor(src, image_gray, COLOR_BGR2GRAY);  //灰度化
	//imshow("image_gray", image_gray);   //显示灰度图像

	//获取图像直方图
	int histsize = 256;
	float ranges[] = { 0,256 };
	const float* histRanges = { ranges };
	calcHist(&image_gray, 1, 0, Mat(), hist, 1, &histsize, &histRanges, true, false);

	//创建直方图显示图像
	int hist_h = 300;//直方图的图像的高
	int hist_w = 512; //直方图的图像的宽
	int bin_w = hist_w / histsize;//直方图的等级
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));//绘制直方图显示的图像

	//绘制并显示直方图
	normalize(hist, hist, 0, hist_h, NORM_MINMAX, -1, Mat());//归一化直方图
	for (int i = 1; i < histsize; i++)
	{
		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(hist.at<float>(i - 1))),
			Point((i)*bin_w, hist_h - cvRound(hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
	}

	imshow("histImage", histImage);
	waitKey(0);  //暂停，保持图像显示，等待按键结束

}

Mat ImageProcess::EqualizeHist(Mat src)
{
	Mat image_gray, image_enhanced;		//定义灰度图像、直方图
	if (src.empty())
	{
		MessageBoxA(NULL, "请先导入图片!!!", "警告", MB_OK);
		return Mat();
	}

	cvtColor(src, image_gray, COLOR_BGR2GRAY);	//灰度化
	//imshow("image_gray", image_gray);	

	equalizeHist(image_gray, image_enhanced);
	//imshow("image_enhanced", image_enhanced);
	return image_enhanced;
}

Mat ImageProcess::GrayScaleLinearTransform(Mat inputImage, double alpha, double beta)
{

	Mat grayImage;
	cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

	//线性变换
	Mat transformImage = Mat::zeros(grayImage.size(), CV_8U);
	for (int y = 0; y < grayImage.rows; y++)
	{
		for (int x = 0; x < grayImage.cols; x++)
		{
			int originPixelValue = static_cast<int>(grayImage.at<uchar>(y, x));
			int newPixelValue = cv::saturate_cast<uchar>(alpha * originPixelValue + beta);
			transformImage.at<uchar>(y, x) = newPixelValue;
		}
	}

	return transformImage;
}

Mat ImageProcess::GrayLogTransform(Mat inputImage, double c)
{

	Mat grayImage;
	cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

	//对数变换 new_image = c * log(1 + origin)
	Mat newTransformImage = Mat::zeros(grayImage.size(),CV_8U);
	for (int y = 0; y < inputImage.rows; y++)
	{
		for (int x = 0; x < inputImage.cols; x++)
		{
			int originalPixelValue = static_cast<int>(grayImage.at<uchar>(y, x));
			int newPixelValue = saturate_cast<uchar>(c * std::log(1 + originalPixelValue));
			newTransformImage.at<uchar>(y, x) = newPixelValue;
		}
	}
	return newTransformImage;
}

Mat ImageProcess::GrayScaleGamaTransform(Mat inputImage, double gama)
{

	Mat grayImage;
	cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

	//灰度伽马变换 new_image = 255 * (origin / 255) ^ gama
	Mat newTransformImage = Mat::zeros(grayImage.size(), CV_8U);
	for (int y = 0; y < inputImage.rows; y++)
	{
		for (int x = 0; x < inputImage.cols; x++)
		{
			int originalPixelValue = static_cast<int>(grayImage.at<uchar>(y, x));
			int newPixelValue = saturate_cast<uchar>(255 * std::pow(originalPixelValue / 255, gama));
			newTransformImage.at<uchar>(y, x) = newPixelValue;
		}
	}
	return newTransformImage;
}

Mat ImageProcess::ImageErosion(Mat inputImage, int erosionSize)
{
	Mat grayImage;
	cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);
	Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * erosionSize + 1, 2 * erosionSize + 1),cv::Point(erosionSize, erosionSize));

	// 进行腐蚀操作
	cv::Mat erodedImage;
	cv::erode(grayImage, erodedImage, element);

	return erodedImage;
}

Mat ImageProcess::ImageDilation(Mat inputImage, int dilationSize)
{
	// 将RGB图像转换为灰度图像
	Mat grayImage;
	cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

	// 定义膨胀核（结构元素）
	Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * dilationSize + 1, 2 * dilationSize + 1),
		cv::Point(dilationSize, dilationSize));

	// 进行膨胀操作
	Mat dilatedImage;
	dilate(grayImage, dilatedImage, element);

	return dilatedImage;
}

Mat ImageProcess::ImageThresholdSegmentation(Mat inputImage, int thresholdSize)
{
	Mat grayImage;
	cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

	Mat segmentImage;
	threshold(grayImage, segmentImage, thresholdSize, 255, cv::THRESH_BINARY);
	return segmentImage;
}

Mat ImageProcess::ImageAdaptiveThresholdSegmentation(Mat inputImage, int blockSize, int subtractValue)
{
	// 将RGB图像转换为灰度图像
	Mat grayImage;
	cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

	// 进行自适应阈值分割
	Mat segmentedAdaptive;
	adaptiveThreshold(grayImage, segmentedAdaptive, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C,
		cv::THRESH_BINARY, blockSize, subtractValue);

	return segmentedAdaptive;
}

Mat ImageProcess::RegionGrowingSegmentation(Mat inputImage, int seedX, int seedY, int thresholdSize)
{
	// 将RGB图像转换为灰度图像
	Mat grayImage;
	cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

	// 初始化分割图像
	Mat segmentedImage = cv::Mat::zeros(grayImage.size(), CV_8U);

	// 获取种子点的初始灰度值
	int seedValue = static_cast<int>(grayImage.at<uchar>(seedY, seedX));

	// 创建队列用于保存待处理的像素坐标
	std::queue<std::pair<int, int>> pixelQueue;
	pixelQueue.push(std::make_pair(seedX, seedY));

	// 开始区域生长
	while (!pixelQueue.empty()) {
		int x = pixelQueue.front().first;
		int y = pixelQueue.front().second;
		pixelQueue.pop();

		// 检查当前像素是否已被处理过
		if (segmentedImage.at<uchar>(y, x) == 0) {
			// 计算当前像素与种子点的灰度差
			int pixelValue = static_cast<int>(grayImage.at<uchar>(y, x));
			int diff = std::abs(seedValue - pixelValue);

			// 如果灰度差小于阈值，则加入分割区域
			if (diff <= thresholdSize) {
				segmentedImage.at<uchar>(y, x) = 255;

				// 将当前像素的邻域加入队列
				for (int dy = -1; dy <= 1; ++dy) {
					for (int dx = -1; dx <= 1; ++dx) {
						int newX = x + dx;
						int newY = y + dy;
						if (newX >= 0 && newX < grayImage.cols && newY >= 0 && newY < grayImage.rows) {
							pixelQueue.push(std::make_pair(newX, newY));
						}
					}
				}
			}
		}
	}

	return segmentedImage;
}

Mat ImageProcess::SobelEdgeDetection(Mat inputImage, int kernelSize)
{
	Mat grayImage;
	cvtColor(inputImage, grayImage, COLOR_BGR2GRAY);

	//进行Sobel边缘监测
	Mat gradientX, gradientY;
	Sobel(grayImage, gradientX, CV_16S, 1, 0, kernelSize);
	Sobel(grayImage, gradientY, CV_16S, 0, 1, kernelSize);

	//计算梯度幅值
	Mat absGradientX, absGradientY;
	convertScaleAbs(gradientX, absGradientX);
	convertScaleAbs(gradientX, absGradientY);

	//合并x和y的梯度幅值
	Mat gradientImage;
	addWeighted(absGradientX, 0.5, absGradientY, 0.5, 0, gradientImage);


	return gradientImage;
}

Mat ImageProcess::CannyEdgeDetection(Mat inputImage, double threshold1, double threshold2)
{
	// 将RGB图像转换为灰度图像
	Mat grayImage;
	cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

	// 进行Canny边缘检测
	Mat edgeImage;
	Canny(grayImage, edgeImage, threshold1, threshold2);

	return edgeImage;
}

Mat ImageProcess::MeanFilter(Mat inputImage, int kernelSize)
{
	Mat filterImage;
	blur(inputImage, filterImage, cv::Size(kernelSize, kernelSize));
	return filterImage;
}

Mat ImageProcess::MedianFilter(Mat inputImage, int kernelSize)
{
	Mat filterImage;
	medianBlur(inputImage, filterImage, kernelSize);
	return filterImage;
}

Mat ImageProcess::GaussianFilter(Mat inputImage, int kernelSize, double sigma)
{
	Mat filterImage;
	GaussianBlur(inputImage, filterImage, cv::Size(kernelSize, kernelSize), sigma);
	return filterImage;
}

