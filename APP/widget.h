#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <menu.h>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);

    }
    bool connOpen(){

        mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/karzo/OneDrive/Bureau/study/School-management-main/APP/Database/Database.db");

    if (!mydb.open()){
        qDebug() << "Failed to open the database";
        return false;}
    else{
        qDebug()<<"Conneted...";
        return true;}
}
    int sqlSize(QSqlQuery query)
    {
        int initialPos = query.at();
        int pos = 0;
        if (query.last())
            pos = query.at() + 1;
        else
            pos = 0;
        query.seek(initialPos);
        return pos;
    }

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
