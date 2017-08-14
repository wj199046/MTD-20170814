#ifndef USERINFOWIDGETS_H
#define USERINFOWIDGETS_H

#include <QWidget>
#include"pixlabelwidget.h"

namespace Ui {
class userInfoWidgets;
}

class userInfoWidgets : public QWidget
{
    Q_OBJECT

public:
    explicit userInfoWidgets(QWidget *parent = 0);
    ~userInfoWidgets();

signals:
    void SendUserInfoContent(QString strName, QString strAge, QString strSex);
    void signalLogInUserId(QString strId);

private slots:

    void changeCurrentTab(PixLabel *pix);

    void on_pushButton_makeSure_2_clicked();

    void on_pushButton_cancel_2_clicked();

    void on_pushButton_makeSure_1_clicked();

    void on_pushButton_cancel_1_clicked();

private:
    Ui::userInfoWidgets *ui;
};

#endif // USERINFOWIDGETS_H
