#ifndef SQLOUT_H
#define SQLOUT_H

#include "mtdsql.h"

class MTDMEDSHARED_EXPORT MtdMed
{
public:
    MtdMed();
    bool deleteUser(int userId); //删除用户/病历
    bool addRecord(MedRecord &record); //添加病历
    bool updateRecord(MedRecord record); //更新病历
    bool searchRecord(QString idOrName, QVector<MedRecord> &vector); //搜索病历
    bool deleteImage(int id); //删除图片
    bool saveResult(MedCheckResult &result); //保存诊断结果
    bool updateResult(MedCheckResult result); //更新诊断
    bool deleteResult(int id); // 删除诊断
    bool selectAllRecord(QVector<MedRecord> &vector); //查找所有病历
    bool selectResult(int userId, QVector<MedCheckResult> &vector); //查找诊断结果
    bool insertAllImage(int userId, QString bodyParts, QVector<QString>, QVector<QImage> images, QVector<MedCheckImage> &imgs);

private:
    MTDSql mtd;
    bool isDigitStr(QString str); // 判断字符串是否为数字
    bool saveImage(int userId, QString bodyPart, QImage img, QString paramer, MedCheckImage &image); //保存图片
};

#endif // SQLOUT_H
