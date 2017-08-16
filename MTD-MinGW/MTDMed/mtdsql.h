#ifndef MTDMED_H
#define MTDMED_H

#include "mtdmed_global.h"
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>

typedef struct _MedCheckImage  //医用数据库的图像定义
{
    int id;	//数据库中图像的id，必须唯一
    int userID; //记录受检者病历的id，便于查找。如果不记录，即视为一般用途图像
    int width;  //图像的宽度
    int height;  //图像的高度
    QString url; //图像文件的路径
    QString bodyPart; //图像拍摄受检者的身体部位说明
    QString paramer; //图像存储过程中的参数
}MedCheckImage;

typedef struct _MedCheckResult
{
    int id;
    int userId;
    QDateTime checkDate; //就诊日期
    QString checkSpot; //就诊地点
    int nDoctorID; //医生编号
    QString doctorName; //医生姓名
    QVector<MedCheckImage> allCheckedImages; //本次就诊所有保存的图像id
    QString symptom; //症状
    QString decision; //诊断结论
    QString therapy; //治疗方法
}MedCheckResult;

typedef struct _MedRecord {
    int userID; //病历库中受检者的id
    QString name; //受检者的姓名
    bool bMale; //受检者的性别
    unsigned int age; //受检者的年龄
    QString contact; //联系方式
    QString address; //病人地址
    QString profession; //病人职业
    QString personalHistory; //个人病史
    QString familyHistory; //家族病史
    QVector<MedCheckResult> allCheckResults; //受检者的历史就诊记录
    QString comment; //受检者的附加信息
}MedRecord;

class MTDSql
{

public:
    MTDSql();
//    AddRecord(MedRecord record);			//录入病历
//    SearchRecord();		//从病历数据库中搜索病历
//    SaveRecordToLocal();	//保存病历到本地
//    SaveImageToLocal();	//保存图像到本地
//    SaveRecordToCloud();	//保存病历到云端
//    SaveImageToCloud();	//保存图像到云端
//    DeleteRecord();		//删除病历
//    GetCheckedImages();	//获得受检者就诊图像
//    GetCheckedResult();	//获得受检者就诊结果
//    GetMedRecord();		//获得受检者病历
//    SearchImage();		//从图像数据库中搜索图像
//    SyncImageBase();		//同步图像数据库
//    SyncRecordBase();		//同步病历数据库
    bool insertToImage(int userId, int width, int height, QString url, QString bodypart, QString paramer);   //向图片数据库插入数据
    bool insertToResult(MedCheckResult &result);  //向诊断结果表中插入数据
    bool insertToRecord(MedRecord &record);  //向病历表中插入数据
    bool deleteImageById(int id);
    bool deleteImageByUserId(int userId);
    bool deleteResultByid(int id);
    bool deleteResultByuserId(int userId);
    bool deleteRecordByUserId(int userId);
    bool updateImageById(MedCheckImage image);
    bool updateResultById(MedCheckResult result);
    bool updateRecordById(MedRecord record);
    MedCheckImage selectImageById(int id);
    QVector<MedCheckImage> selectImageByUserId(int userId);
    bool selectLastImage(MedCheckImage &image);
    bool selectLastResult(MedCheckResult &result);
    bool selectLastRecord(MedRecord &record);
    bool selectResultById(int id, MedCheckResult &result);
    bool selectResultByUserId(int userId, QVector<MedCheckResult> &vector);
    QVector<MedCheckResult> selectResultByUserIdAndCheckDate(int userId, QDateTime startTime, QDateTime endTime);
    QVector<MedCheckResult> selectResultByDoctorIdAndCheckDate(int doctorId, QDateTime startTime, QDateTime endTime);
    bool selectRecordByUserId(int userId, MedRecord &record);
    bool selectRecordByName(QString name, QVector<MedRecord> &vector);
    bool selectAllRecord(QVector<MedRecord> &vector);

private:
    //QSqlDatabase db;
    bool createConnection();    //创建数据库连接
    bool createTable();     //创建数据表



};

#endif // MTDMED_H
