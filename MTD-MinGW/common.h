#ifndef COMMON_H
#define COMMON_H

#include<QString>

class Common
{
public:
    struct stDiagnoseRst
    {
        QString strDoctorId;     //医生Id
        QString strDoctorName;   //医生姓名
        QString strPlace;        //地点
        QString strSymptom;      //症状
        QString strDecision;     //诊断结果
        QString strTherapy;      //治疗方法
    };

    struct stUserSigninInfo
    {
        QString strName;            //患者姓名
        QString strGender;          //患者性别
        QString strAge;             //患者年龄
        QString strProfession;      //患者职业
        QString strPhone;           //联系方式
        QString strPlace;           //患者住址
        QString strPersonalHistory; //个人病史
        QString strFamilyHistory;   //家族病史
        QString strComment;         //受检者的附加信息
    };


};

#endif // COMMON_H
