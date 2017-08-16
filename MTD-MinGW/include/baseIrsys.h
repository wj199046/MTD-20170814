#ifndef BASEIRSYS_H
#define BASEIRSYS_H

#include <windows.h>
class  BaseIRsys
{
public:

    //初始化摄像头，并启动
    virtual int Start(HWND hWnd) = 0;

    //停止
    virtual int Stop() = 0;

    //获取摄像头数据
    virtual bool Capture(UCHAR* d) = 0;

    //获取摄像头数据宽度
    virtual const int GetWidth() const  = 0;

    //获取摄像头数据高度
    virtual const int GetHeight() const  = 0;

    //获取数据字节宽度
    virtual const int GetStoreBytes() const = 0;

    //灰度数据转换成温度数据
    virtual const double GraytoTemp(USHORT iGray) = 0;

    //温度数据转换成灰度数据
    virtual const USHORT TemptoGray(double iTemp) = 0;

    //获取摄像头帧率
    virtual const USHORT GetFPS() const = 0;

    //获取所需的调色板文件路径,并返回调色板数据
    virtual UCHAR* SetXmlPath(char* strPath) = 0;

    //校正
    virtual void Correction() = 0;

    /***********串口操作*************/
    //串口消息(可以不使用)
    virtual void SerialPortMsg(char ch) = 0;

    //升降机上行
    virtual void CameraUp() = 0;

    //升降机下行
    virtual void CameraDown() = 0;

    //升降机停止运行
    virtual void CameraControlStop() = 0;

    //控制命令：调焦（左、右调焦，停止）
    virtual void Control_autoleft() = 0;
    virtual void Control_autoright() = 0;
    virtual void Control_stop() = 0;

};

#ifdef IRSYS_DLL_EXPORT
#define IRSYS_DLL __declspec(dllexport)
#else
#define IRSYS_DLL __declspec(dllimport)
#endif

//extern "C" IRSYS_DLL BaseIRsys * GetIRSysDllObj();
//extern "C" IRSYS_DLL void ReleaseIRSysDllObj(BaseIRsys *pBI);

typedef BaseIRsys*(*pfn_GetIRSysDllObj)();
typedef void(*pfn_ReleaseIRSysDllObj)(BaseIRsys*);

#define GETIRSYSDLLOBJ_FUNC_NAME        "GetIRSysDllObj"
#define RELEASEIRSYSDLLOBJ_FUNC_NAME    "ReleaseIRSysDllObj"

#endif // BASEIRSYS_H
