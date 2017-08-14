#ifndef MTD_IMAGE_H
#define MTD_IMAGE_H
#include"include/opencv2/core.hpp"
#include"mtd_camera_ste.h"
#include<QObject>
#include "mtdcameracore_global.h"
#include<QImage>
class MTDCAMERACORESHARED_EXPORT MTDImage
{
public:
    MTDImage(int width,int height);
    virtual ~MTDImage();
public:
    QImage dst2QImage();//处理过后的图像,用于显示
    QImage res2QImage();//未处理的图像,用于显示

    MTDImage* clone();//复制,指针自己释放
    void reSet();//参数重置
    int getHeight();//获取图像高度
    int getWidth();//获取图像宽度

    MTD::ImageParamer getParamer() const;//获取处理参数
    void setParamer(const MTD::ImageParamer &value);//设置处理参数

    cv::Mat *getRes() const;//获取缓存的原始图片指针
    void setRes(cv::Mat *value);//设置原始图片指针

    cv::Mat *getDst() const;//获取缓存的处理后的图片指针

private:
    void notifyDataChange();
    MTD::ImageParamer paramer;
    cv::Mat* res;
    cv::Mat* dst;
    int m_nWidth;
    int m_nHeight;
};
#endif // MTD_IMAGE_H
