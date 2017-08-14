#ifndef MTD_UTIL_H
#define MTD_UTIL_H
#include"include/opencv2/highgui.hpp"
#include"include/opencv2/imgproc.hpp"
#include "include/opencv2/core.hpp"
#include<QtCore>
#include "mtdcameracore_global.h"
#include"include/mtdmed.h"
#include<QImage>
class MTDImage;
class MTDCAMERACORESHARED_EXPORT MTDUtil
{
public :
    static void ReverseArray(unsigned char *&,int);//反转数组
    static void RGB2HLS( uint8_t *h, uint8_t *l, uint8_t *s, uint8_t r, uint8_t g, uint8_t b);//rgb转hls
    static void HLS2RGB( uint8_t *r, uint8_t *g, uint8_t *b, uint8_t hh, uint8_t ll, uint8_t ss);//hls转rgb
    static cv::Mat getHistImg(const cv::Mat * mat);//获取灰度直方图
    static cv::Mat segmImage(cv::Mat gray_image,cv::Mat canny_image);//Canndy边缘连线
    static double getSobelValue(cv::Mat *res);//获取sobel导数的值,值越大,聚焦越好

    static void insertAllImage(MtdMed * med, int userId, QString bodyParts, QVector<MTDImage *>images, QVector<MedCheckImage> &imgs);//插入图片至数据库

    static MTDImage* loadImage(MedCheckImage &image);//从数据库读出图片,生成的指针自行管理
private:
    static double HLS2RGBvalue(double n1,double n2, double hue);
};
#endif // MTD_UTIL_H
