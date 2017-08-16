#ifndef BASEIRSYS_H
#define BASEIRSYS_H

#include <windows.h>
class  BaseIRsys
{
public:

    //��ʼ������ͷ��������
    virtual int Start(HWND hWnd) = 0;

    //ֹͣ
    virtual int Stop() = 0;

    //��ȡ����ͷ����
    virtual bool Capture(UCHAR* d) = 0;

    //��ȡ����ͷ���ݿ��
    virtual const int GetWidth() const  = 0;

    //��ȡ����ͷ���ݸ߶�
    virtual const int GetHeight() const  = 0;

    //��ȡ�����ֽڿ��
    virtual const int GetStoreBytes() const = 0;

    //�Ҷ�����ת�����¶�����
    virtual const double GraytoTemp(USHORT iGray) = 0;

    //�¶�����ת���ɻҶ�����
    virtual const USHORT TemptoGray(double iTemp) = 0;

    //��ȡ����ͷ֡��
    virtual const USHORT GetFPS() const = 0;

    //��ȡ����ĵ�ɫ���ļ�·��,�����ص�ɫ������
    virtual UCHAR* SetXmlPath(char* strPath) = 0;

    //У��
    virtual void Correction() = 0;

    /***********���ڲ���*************/
    //������Ϣ(���Բ�ʹ��)
    virtual void SerialPortMsg(char ch) = 0;

    //����������
    virtual void CameraUp() = 0;

    //����������
    virtual void CameraDown() = 0;

    //������ֹͣ����
    virtual void CameraControlStop() = 0;

    //����������������ҵ�����ֹͣ��
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
