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

};

#endif // COMMON_H
