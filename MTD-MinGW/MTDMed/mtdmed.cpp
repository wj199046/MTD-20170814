#include "mtdmed.h"
#include <QDir>
#include <QImage>

MtdMed::MtdMed()
{

}

bool MtdMed::deleteUser(int userId)
{
    bool imageFlag = mtd.deleteImageByUserId(userId);
    bool resultFlag = mtd.deleteResultByuserId(userId);
    bool recordFlag = mtd.deleteRecordByUserId(userId);
    if(imageFlag && resultFlag && recordFlag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MtdMed::addRecord(MedRecord &record)
{
    bool recordFlag = mtd.insertToRecord(record);
    if(recordFlag)
    {
        mtd.selectLastRecord(record);
        return true;
    }
    else
    {
        return false;
    }
}

bool MtdMed::updateRecord(MedRecord record)
{
    return mtd.updateRecordById(record);
}

bool MtdMed::searchRecord(QString idOrName, QVector<MedRecord> &vector)
{
    MedRecord record;
    if(isDigitStr(idOrName) && idOrName != NULL)
    {
        bool flag = mtd.selectRecordByUserId(idOrName.toInt(), record);
        if (flag)
        {
            vector.append(record);
            return true;
        }
        else
        {
            return false;
        }
//        vector.append(record);
//        return true;
    }
    else
    {
        mtd.selectRecordByName(idOrName, vector);
        return true;
    }
}

bool MtdMed::saveImage(int userId, QString bodyPart, QImage img, QString paramer, MedCheckImage &image)
{
    QString dirName = "images/" + QString::number(userId);
    QDir dir(dirName);
    bool dirFlag = true;
    if(!dir.exists())
    {
        dirFlag = dir.mkpath(dirName);
    }

    if(!dirFlag)
    {
        return false;
    }

    if(!mtd.insertToImage(userId, img.width(), img.height(), "", bodyPart, paramer))
    {
        return false;
    }
    mtd.selectLastImage(image);
    QString imageName = QString::number(image.id) + ".png";
    QString imagePath = dirName + "\\" + imageName;
    if(!img.save(imagePath, "png"))
    {
        return false;
    }
    image.url = imagePath;
    if(!mtd.updateImageById(image))
    {
        return false;
    }

    return true;
}

bool MtdMed::deleteImage(int id)
{
    return mtd.deleteImageById(id);
}

bool MtdMed::saveResult(MedCheckResult &result)
{

    bool resultFlag = mtd.insertToResult(result);

    mtd.selectLastResult(result);

    MedRecord record;
    mtd.selectRecordByUserId(result.userId, record);
    record.allCheckResults.append(result);
    bool recordFlag = mtd.updateRecordById(record);

    if(resultFlag && recordFlag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MtdMed::updateResult(MedCheckResult result)
{
    return mtd.updateResultById(result);
}

bool MtdMed::deleteResult(int id)
{
    MedCheckResult result;
    mtd.selectResultById(id, result);
    if(result.allCheckedImages.size() > 0)
    {
        for(int i = 0; i < result.allCheckedImages.size(); i ++)
        {
            deleteImage(result.allCheckedImages.at(i).id);
        }
    }
    bool resultFlag = mtd.deleteResultByid(id);
    MedRecord record;
    mtd.selectRecordByUserId(result.userId, record);
    bool recordFlag = mtd.updateRecordById(record);

    if(resultFlag && recordFlag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MtdMed::selectAllRecord(QVector<MedRecord> &vector)
{
    return mtd.selectAllRecord(vector);
}

bool MtdMed::selectResult(int userId, QVector<MedCheckResult> &vector)
{
    return mtd.selectResultByUserId(userId, vector);
}

bool MtdMed::insertAllImage(int userId, QString bodyParts, QVector<QString> paramers, QVector<QImage> images, QVector<MedCheckImage> &imgs)
{
    bool flag = true;
    imgs.clear();
    for(int i = 0; i < images.size(); i ++)
    {
        MedCheckImage image;
        flag = saveImage(userId, bodyParts, images[i], paramers[i], image);
        imgs.append(image);
    }
    return flag;
}

bool MtdMed::selectResultById(int id, MedCheckResult &result)
{
    return mtd.selectResultById(id, result);
}

bool MtdMed::isDigitStr(QString str)
{
    QByteArray ba = str.toLatin1();//QString 转换为 char*
    const char *s = ba.data();

    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    { //不是纯数字
        return false;
    }
    else
    { //纯数字
        return true;
    }

}
