#ifndef MTD_CAMERA_STE_H
#define MTD_CAMERA_STE_H

namespace MTD {
#define VERSION_CODE 1
enum CameraControl{Camera_Up,//相机镜头上移
                   Camera_Down,//相机镜头下移
                   Camera_Stop,//相机镜头停止
                   Focus_Up,//焦距+
                   Focus_Down,//焦距-
                   Focus_Stop,//变焦停止
                   Auto_Focus,//自动对焦
                   Catch,//抓图,实际为内部计时器停止
                   Refresh//重启计时器
                  };
enum ColorGradation{Gray=0,//黑白
                    Color160=1,//160色
                    Color80=2,//80色
                    Color40=4,//40色
                    Color20=8//20色
                   };
#if VERSION_CODE==1
typedef struct {
    bool waveFilter;//滤波
    bool polarChange;//极性交换
    bool histogramStretch;//直方图均衡
    int canndy;//边缘检测
    int temLow;//温度下限
    int temHigh;//温度上限
    int temMid;//中间温度
    ColorGradation gradation;//色彩空间
}ImageParamer;
#endif
}
#endif // MTD_CAMERA_STE_H
