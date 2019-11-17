#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QIcon>
#include <QPushButton>
#include <QLCDNumber>
#include <QRegExp>
#include <QLabel>
#include <QKeyEvent>


using namespace std;



class Calculator : public QWidget
{
    Q_OBJECT
private:


double Calculate();
QPushButton* CreateButton(const QIcon icon);
QPushButton* CreateButton(const QString name);
void keyPressEvent(QKeyEvent *key);


QGridLayout *lay = new QGridLayout;
QString names[5][4] = {{"CE","C"," ","="},
                       {"1","2","3","*"},
                       {"4","5","6","/"},
                       {"7","8","9","-"},
                       {"^","0",".","+"}};
QLCDNumber* num = new QLCDNumber(16);
QString str1[2];
QString str;
QLabel *text = new QLabel("");
int k = 0;
QIcon ico;
QString oldstr = "";
int symnum = 0;



public:
    Calculator(QWidget *parent = nullptr);


public slots:

    void ButtonClicked();

};








#endif // MAINWINDOW_H
