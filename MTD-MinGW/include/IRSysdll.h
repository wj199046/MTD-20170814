class CMyUSBInterface;

class __declspec(dllexport)  IRSysDll
{
public:
        IRSysDll();

        ~IRSysDll(void);

        int Start(HWND hWnd);//初始化摄像头，并启动

        int Stop();//停止

        bool Capture(UCHAR* &d);//获取摄像头数据

        //获取摄像头数据宽度
        const int GetWidth() const;

        //获取摄像头数据高度
        const int GetHeight() const;

        //获取数据字节宽度
        const int GetStoreBytes() const;

        //灰度数据转换成温度数据
        const double GraytoTemp(unsigned short iGray);

        //温度数据转换成灰度数据
        const ushort TemptoGray(double iTemp);

        //获取摄像头帧率
        const ushort GetFPS() const;

        //获取所需的调色板文件路径,并返回调色板数据
        uchar* SetXmlPath(char* strPath);

        //校正
        void Correction();

        //串口操作
        //串口消息(可以不使用)
        void SerialPortMsg(char ch);
        //升降机上行
        void CameraUp();
        //升降机下行
        void CameraDown();
        //升降机停止运行
        void CameraControlStop();

        //控制命令：调焦（左、右调焦，停止）
        void Control_autoleft();
        void Control_autoright();
        void Control_stop();

public:
        int m_Status;

private:
        int m_width;
        int m_height;
        int m_bytes;
        CMyUSBInterface* m_cap;//USB设备
        UINT_PTR iID ;

};
