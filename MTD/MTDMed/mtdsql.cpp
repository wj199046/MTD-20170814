#include "mtdsql.h"

#include<QFile>

MTDSql::MTDSql()
{
    createConnection();
    createTable();

}

bool MTDSql::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "mtdData");
    db.setDatabaseName(".//MTDDb."
                       "db");
    if( !db.open())
    {
        qDebug() << QStringLiteral("无法建立数据库连接") << endl;
        return false;
    }

    qDebug() << QStringLiteral("建立数据库连接成功") << endl;
    return true;

}

bool MTDSql::createTable()
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    bool imageSuccess = query.exec("create table med_check_image(id INTEGER PRIMARY KEY autoincrement,user_id int,width int,height int,url varchar,bodypart varchar,paramer varchar)");
    if(imageSuccess)
    {
        qDebug() << QStringLiteral("图像数据库表创建成功！") << endl;
    }
    else
    {
        qDebug() << QStringLiteral("图像数据库表创建失败！") << endl;
    }

    bool resultSuccess = query.exec("create table med_check_result(id INTEGER PRIMARY KEY autoincrement,user_id int,check_date datetime,check_spot varchar,doctor_id int,doctor_name varchar,"
                                    "image_ids varchar,symptom varchar,decision varchar,therapy varchar)");
    if(resultSuccess)
    {
        qDebug() << QStringLiteral("结果数据库表创建成功！\n");
    }
    else
    {
        qDebug() << QStringLiteral("结果数据库表创建失败！\n");
    }

    bool recordSuccess = query.exec("create table med_check_record(user_id INTEGER PRIMARY KEY autoincrement,name varchar,bmale boolean,age tinyint,result_ids varchar,contact varchar,"
                                    "address varchar,profession varchar,personal_history varchar,family_history varchar,comment varchar)");
    if(recordSuccess)
    {
        qDebug() << QStringLiteral("病历数据库表创建成功！\n");
    }
    else
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("病历数据库表创建失败！\n");
    }

    if(imageSuccess && resultSuccess && recordSuccess)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool MTDSql::insertToImage(int userId, int width, int height, QString url, QString bodypart, QString paramer)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into med_check_image(user_id,width,height,url,bodypart,paramer) values(?,?,?,?,?,?)");
    query.bindValue(0, userId);
    query.bindValue(1, width);
    query.bindValue(2, height);
    query.bindValue(3, url);
    query.bindValue(4, bodypart);
    query.bindValue(5, paramer);

    bool success = query.exec();

    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("插入照片失败");
        return false;
    }
    return true;
}

bool MTDSql::insertToResult(MedCheckResult &result)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into med_check_result(user_id,check_date,check_spot,doctor_id,doctor_name,image_ids,symptom,decision,therapy) values (?,?,?,?,?,?,?,?,?)");
    QDateTime checkTime = QDateTime::currentDateTime();
    QString str = checkTime.toString("yyyy-MM-dd hh:mm:ss");
    result.checkDate = checkTime;
    query.bindValue(0, result.userId);
    query.bindValue(1, str);
    query.bindValue(2, result.checkSpot);
    query.bindValue(3, result.nDoctorID);
    query.bindValue(4, result.doctorName);
    QString ids = "";
    for(int i = 0; i < result.allCheckedImages.size(); i ++)
    {
        ids = ids + QString::number(result.allCheckedImages[i].id) + ",";
    }
    query.bindValue(5, ids);
    query.bindValue(6, result.symptom);
    query.bindValue(7, result.decision);
    query.bindValue(8, result.therapy);

    bool success = query.exec();

    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("插入诊断报告失败");
        return false;
    }
    return true;
}

bool MTDSql::insertToRecord(MedRecord &record)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into med_check_record(name,bmale,age,result_ids,contact,address,profession,personal_history,family_history,comment) values (?,?,?,?,?,?,?,?,?,?)");
    query.bindValue(0, record.name);
    query.bindValue(1, record.bMale);
    query.bindValue(2, record.age);
    QString ids = "";
    for(int i = 0; i < record.allCheckResults.size(); i ++)
    {
        ids = ids + QString::number(record.allCheckResults[i].id) + ",";
    }
    query.bindValue(3, ids);
    query.bindValue(4, record.contact);
    query.bindValue(5, record.address);
    query.bindValue(6, record.profession);
    query.bindValue(7, record.personalHistory);
    query.bindValue(8, record.familyHistory);
    query.bindValue(9, record.comment);

    bool success = query.exec();

    if (!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("插入病历失败");
        return false;
    }
    return true;
}

bool MTDSql::deleteImageById(int id)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query1(db);
    query1.prepare("select url from med_check_image where id=?");
    query1.bindValue(0, id);
    query1.exec();
    query1.first();
    QString url = query1.value(0).toString();
    QFile image(url);
    if(!image.remove())
    {
        return false;
    }
    QSqlQuery query(db);
    query.prepare("delete from med_check_image where id=?");
    query.bindValue(0, id);
    bool success = query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("删除照片失败");
        return false;
    }

    return true;
}

bool MTDSql::deleteImageByUserId(int userId)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query1(db);
    query1.prepare("select url from med_check_image where user_id=?");
    query1.bindValue(0, userId);
    query1.exec();
    QString url = "";
    while(query1.next())
    {
        url = query1.value("url").toString();
        QFile image(url);
        if(!image.remove())
        {
            return false;
        }
    }

    QSqlQuery query(db);
    query.prepare("delete from med_check_image where user_id=?");
    query.bindValue(0, userId);
    bool success = query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("删除照片失败");
        return false;
    }

    return true;
}

bool MTDSql::deleteResultByid(int id)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("delete from med_check_result where id=?");
    query.bindValue(0, id);
    bool success = query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("删除诊断报告失败");
        return false;
    }

    return true;
}

bool MTDSql::deleteResultByuserId(int userId)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("delete from med_check_result where user_id=?");
    query.bindValue(0, userId);
    bool success = query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("删除照片失败");
        return false;
    }

    return true;
}

bool MTDSql::deleteRecordByUserId(int userId)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("delete from med_check_record where user_id=?");
    query.bindValue(0, userId);
    bool success = query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("删除病历失败");
        return false;
    }

    return true;
}

bool MTDSql::updateImageById(MedCheckImage image)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("update med_check_image set user_id=?,width=?,height=?,url=?,bodypart=?,paramer=? where id=?");
    query.bindValue(0, image.userID);
    query.bindValue(1, image.width);
    query.bindValue(2, image.height);
    query.bindValue(3, image.url);
    query.bindValue(4, image.bodyPart);
    query.bindValue(5, image.paramer);
    query.bindValue(6, image.id);
    bool success = query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("更新照片失败");
        return false;
    }

    return true;
}

bool MTDSql::updateResultById(MedCheckResult result)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("update med_check_result set user_id=?,check_date=?,check_spot=?,doctor_id=?,"
                  "doctor_name=?,image_ids=?,symptom=?,decision=?,therapy=? where id=?");
    query.bindValue(0, result.userId);
    query.bindValue(1, result.checkDate);
    query.bindValue(2, result.checkSpot);
    query.bindValue(3, result.nDoctorID);
    query.bindValue(4, result.doctorName);
    QString imageIds = "";
    for(int i = 0; i < result.allCheckedImages.size(); i ++)
    {
        imageIds = imageIds + QString::number(result.allCheckedImages[i].id) + ",";
    }
    query.bindValue(5, imageIds);
    query.bindValue(6, result.symptom);
    query.bindValue(7, result.decision);
    query.bindValue(8, result.therapy);
    query.bindValue(9, result.id);
    bool success = query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("更新诊断报告失败");
        return false;
    }

    return true;
}

bool MTDSql::updateRecordById(MedRecord record)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("update med_check_record set name=?,bmale=?,age=?,result_ids=?,contact=?,address=?,profession=?,personal_history=?,family_history=?,comment=? where user_id=?");
    query.bindValue(0, record.name);
    query.bindValue(1, record.bMale);
    query.bindValue(2, record.age);
    QString ids = "";
    for(int i = 0; i < record.allCheckResults.size(); i ++)
    {
        ids = ids + QString::number(record.allCheckResults[i].id) + ",";
    }
    query.bindValue(3, ids);
    query.bindValue(4, record.contact);
    query.bindValue(5, record.address);
    query.bindValue(6, record.profession);
    query.bindValue(7, record.personalHistory);
    query.bindValue(8, record.familyHistory);
    query.bindValue(9, record.comment);
    query.bindValue(10, record.userID);
    bool success = query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("更新病历失败");
        return false;
    }

    return true;
}

MedCheckImage MTDSql::selectImageById(int id)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("select * from med_check_image where id=?");
    query.bindValue(0, id);
    query.exec();
    MedCheckImage image;
    if(query.first())
    {
        image.id = query.value("id").toInt();
        image.userID = query.value("user_id").toInt();
        image.width = query.value("width").toInt();
        image.height = query.value("height").toInt();
        image.url = query.value("url").toString();
        image.bodyPart = query.value("bodypart").toString();
        image.paramer = query.value("paramer").toString();
    }
    return image;
}

QVector<MedCheckImage> MTDSql::selectImageByUserId(int userId)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("select * from med_check_image where user_id=?");
    query.bindValue(0, userId);
    query.exec();
    QVector<MedCheckImage> vector;
    MedCheckImage image;
    while (query.next()) {
        image.id = query.value("id").toInt();
        image.userID = query.value("user_id").toInt();
        image.width = query.value("width").toInt();
        image.height = query.value("height").toInt();
        image.url = query.value("url").toString();
        image.bodyPart = query.value("bodypart").toString();
        image.paramer = query.value("paramer").toString();
        vector.append(image);
    }
    return vector;
}

bool MTDSql::selectResultById(int id, MedCheckResult &result)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("select * from med_check_result where id=?");
    query.bindValue(0, id);
    bool flag = query.exec();
    result.id = 0;
    if(query.next())
    {
        result.id = query.value("id").toInt();
        result.userId = query.value("user_id").toInt();
        result.checkDate = query.value("check_date").toDateTime();
        result.checkSpot = query.value("check_spot").toString();
        result.nDoctorID = query.value("doctor_id").toInt();
        result.doctorName = query.value("doctor_name").toString();
        QStringList ids = query.value("image_ids").toString().split(",");
        result.allCheckedImages.clear();
        if(ids.size() > 0)
        {
            for(int i = 0; i < ids.size()-1; i ++)
            {
                result.allCheckedImages.append(selectImageById(ids[i].toInt()));
            }
        }
        result.symptom = query.value("symptom").toString();
        result.decision = query.value("decision").toString();
        result.therapy = query.value("therapy").toString();
    }
    return flag;
}

bool MTDSql::selectResultByUserId(int userId, QVector<MedCheckResult> &vector)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("select * from med_check_result where user_id=?");
    query.bindValue(0, userId);
    bool flag = query.exec();

    MedCheckResult result;
    while (query.next()) {
        result.id = query.value("id").toInt();
        result.userId = query.value("user_id").toInt();
        result.checkDate = query.value("check_date").toDateTime();
        result.checkSpot = query.value("check_spot").toString();
        result.nDoctorID = query.value("doctor_id").toInt();
        result.doctorName = query.value("doctor_name").toString();
        QStringList ids = query.value("image_ids").toString().split(",");
        result.allCheckedImages.clear();
        if(ids.size() > 0)
        {
            for(int i = 0; i < ids.size()-1; i ++)
            {
                result.allCheckedImages.append(selectImageById(ids[i].toInt()));
            }
        }
        result.symptom = query.value("symptom").toString();
        result.decision = query.value("decision").toString();
        result.therapy = query.value("therapy").toString();
        vector.append(result);
    }
    return flag;
}

QVector<MedCheckResult> MTDSql::selectResultByUserIdAndCheckDate(int userId, QDateTime startTime, QDateTime endTime)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("select * from med_check_result where user_id=? AND check_date between ? and ?");
    query.bindValue(0, userId);
    query.bindValue(1, startTime.toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(2, endTime.toString("yyyy-MM-dd hh:mm:ss"));
    bool success = query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QStringLiteral("查找失败");
    }

    QVector<MedCheckResult> vector;
    MedCheckResult result;
    while (query.next()) {
        result.id = query.value("id").toInt();
        result.userId = query.value("user_id").toInt();
        result.checkDate = query.value("check_date").toDateTime();
        result.checkSpot = query.value("check_spot").toString();
        result.nDoctorID = query.value("doctor_id").toInt();
        result.doctorName = query.value("doctor_name").toString();
        QStringList ids = query.value("image_ids").toString().split(",");
        result.allCheckedImages.clear();
        if(ids.size() > 0)
        {
            for(int i = 0; i < ids.size()-1; i ++)
            {
                result.allCheckedImages.append(selectImageById(ids[i].toInt()));
            }
        }
        result.symptom = query.value("symptom").toString();
        result.decision = query.value("decision").toString();
        result.therapy = query.value("therapy").toString();
        vector.append(result);
    }
    return vector;
}

QVector<MedCheckResult> MTDSql::selectResultByDoctorIdAndCheckDate(int doctorId, QDateTime startTime, QDateTime endTime)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("select * from med_check_result where doctor_id=? AND check_date between ? and ?");
    query.bindValue(0, doctorId);
    query.bindValue(1, startTime);
    query.bindValue(2, endTime);
    query.exec();

    QVector<MedCheckResult> vector;
    MedCheckResult result;
    while (query.next()) {
        result.id = query.value("id").toInt();
        result.userId = query.value("user_id").toInt();
        result.checkDate = query.value("check_date").toDateTime();
        result.checkSpot = query.value("check_spot").toString();
        result.nDoctorID = query.value("doctor_id").toInt();
        result.doctorName = query.value("doctor_name").toString();
        QStringList ids = query.value("image_ids").toString().split(",");
        result.allCheckedImages.clear();
        if(ids.size() > 0)
        {
            for(int i = 0; i < ids.size()-1; i ++)
            {
                result.allCheckedImages.append(selectImageById(ids[i].toInt()));
            }
        }
        result.symptom = query.value("symptom").toString();
        result.decision = query.value("decision").toString();
        result.therapy = query.value("therapy").toString();
        vector.append(result);
    }
    return vector;
}

bool MTDSql::selectRecordByUserId(int userId, MedRecord &record)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("select * from med_check_record where user_id=?");
    query.bindValue(0, userId);
    query.exec();
//    record.userID = 0;
    bool flag;
    if(flag = query.next())
    {
        record.userID = query.value("user_id").toInt();
        record.name = query.value("name").toString();
        record.bMale = query.value("bmale").toBool();
        record.age = query.value("age").toUInt();
        record.contact = query.value("contact").toString();
        record.address = query.value("address").toString();
        record.profession = query.value("profession").toString();
        record.personalHistory = query.value("personal_history").toString();
        record.familyHistory = query.value("family_history").toString();
        record.comment = query.value("comment").toString();
        QStringList ids = query.value("result_ids").toString().split(",");
        record.allCheckResults.clear();
        if(ids.size() > 0)
        {
            for(int i = 0; i < ids.size(); i ++)
            {
                MedCheckResult result;
                selectResultById(ids[i].toInt(), result);
                if(result.id == 0)
                {
                    continue;
                }
                record.allCheckResults.append(result);
            }

        }

    }
    return flag;
}

bool MTDSql::selectRecordByName(QString name, QVector<MedRecord> &vector)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    bool flag = query.prepare("select * from med_check_record where name=?");
    query.bindValue(0, name);
    query.exec();

    MedRecord record;
    while (query.next()) {
        record.userID = query.value("user_id").toInt();
        record.name = query.value("name").toString();
        record.bMale = query.value("bmale").toBool();
        record.age = query.value("age").toUInt();
        record.contact = query.value("contact").toString();
        record.address = query.value("address").toString();
        record.profession = query.value("profession").toString();
        record.personalHistory = query.value("personal_history").toString();
        record.familyHistory = query.value("family_history").toString();
        record.comment = query.value("comment").toString();
        QStringList ids = query.value("result_ids").toString().split(",");
        record.allCheckResults.clear();
        if(ids.size() > 0)
        {
            for(int i = 0; i < ids.size(); i ++)
            {
                MedCheckResult result;
                selectResultById(ids[i].toInt(), result);
                if(result.id == 0)
                {
                    continue;
                }
                record.allCheckResults.append(result);
            }

        }
        vector.append(record);
    }
    return flag;
}

bool MTDSql::selectLastImage(MedCheckImage &image)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    bool flag = query.exec("select * from med_check_image order by id desc limit 1");

    if(query.next())
    {
        image.id = query.value("id").toInt();
        image.userID = query.value("user_id").toInt();
        image.width = query.value("width").toInt();
        image.height = query.value("height").toInt();
        image.url = query.value("url").toString();
        image.bodyPart = query.value("bodypart").toString();
        image.paramer = query.value("paramer").toString();
    }
    return flag;
}

bool MTDSql::selectLastResult(MedCheckResult &result)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    bool flag = query.exec("select * from med_check_result order by id desc limit 1");

    if(query.next())
    {
        result.id = query.value("id").toInt();
        result.userId = query.value("user_id").toInt();
        result.checkDate = query.value("check_date").toDateTime();
        result.checkSpot = query.value("check_spot").toString();
        result.nDoctorID = query.value("doctor_id").toInt();
        result.doctorName = query.value("doctor_name").toString();
        QStringList ids = query.value("image_ids").toString().split(",");

        result.allCheckedImages.clear();
        if(ids.size() > 0)
        {
            for(int i = 0; i < ids.size()-1; i ++)
            {
                result.allCheckedImages.append(selectImageById(ids[i].toInt()));
            }
        }

        result.symptom = query.value("symptom").toString();
        result.decision = query.value("decision").toString();
        result.therapy = query.value("therapy").toString();

    }
    return flag;

}

bool MTDSql::selectLastRecord(MedRecord &record)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    bool flag = query.exec("select * from med_check_record order by user_id desc limit 1");

    if(query.next())
    {
        record.userID = query.value("user_id").toInt();
        record.name = query.value("name").toString();
        record.bMale = query.value("bmale").toBool();
        record.age = query.value("age").toUInt();
        record.contact = query.value("contact").toString();
        record.address = query.value("address").toString();
        record.profession = query.value("profession").toString();
        record.personalHistory = query.value("personal_history").toString();
        record.familyHistory = query.value("family_history").toString();
        record.comment = query.value("comment").toString();
        QStringList ids = query.value("result_ids").toString().split(",");
        record.allCheckResults.clear();
        if(ids.size() > 0)
        {
            for(int i = 0; i < ids.size(); i ++)
            {
                MedCheckResult result;
                selectResultById(ids[i].toInt(), result);
                if(result.id == 0)
                {
                    continue;
                }
                record.allCheckResults.append(result);
            }

        }

    }
    return flag;

}

bool MTDSql::selectAllRecord(QVector<MedRecord> &vector)
{
    QSqlDatabase db = QSqlDatabase::database("mtdData"); //建立数据库连接
    QSqlQuery query(db);
    bool flag = query.exec("select * from med_check_record");

    MedRecord record;
    while (query.next()) {
        record.userID = query.value("user_id").toInt();
        record.name = query.value("name").toString();
        record.bMale = query.value("bmale").toBool();
        record.age = query.value("age").toUInt();
        record.contact = query.value("contact").toString();
        record.address = query.value("address").toString();
        record.profession = query.value("profession").toString();
        record.personalHistory = query.value("personal_history").toString();
        record.familyHistory = query.value("family_history").toString();
        record.comment = query.value("comment").toString();
        QStringList ids = query.value("result_ids").toString().split(",");
        record.allCheckResults.clear();
        if(ids.size() > 0)
        {
            for(int i = 0; i < ids.size(); i ++)
            {
                MedCheckResult result;
                selectResultById(ids[i].toInt(), result);
                if(result.id == 0)
                {
                    continue;
                }
                record.allCheckResults.append(result);
            }

        }
        vector.append(record);
    }
    return flag;
}
