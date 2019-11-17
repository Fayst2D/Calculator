#include "mainwindow.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent)
{


       ico = QPixmap("D:/img_163135");


       lay->addWidget(text,0,1,1,4);
       lay->addWidget(num,1,1,1,4);

       for(int i(0);i < 5;i++)
       {
           for(int j(0);j < 4;j++)
           {
               lay->addWidget(CreateButton(names[i][j]),i + 2,j + 1);
           }
       }

            lay->addWidget(CreateButton(ico),2,3);

setLayout(lay);






}



QPushButton* Calculator :: CreateButton(const QString name)
{

    QPushButton* a = new QPushButton(name);
    connect(a,SIGNAL(clicked()),this,SLOT(ButtonClicked()));
    a->setMinimumSize(50,50);
    return a;
}

QPushButton* Calculator :: CreateButton(const QIcon icon )
{

    QPushButton* a = new QPushButton(icon," ");

    connect(a,SIGNAL(clicked()),this,SLOT(ButtonClicked()));
    a->setMinimumSize(50,50);
    return a;
}

void Calculator :: keyPressEvent(QKeyEvent *key)
{

    QPushButton * p = (QPushButton*)(lay->itemAtPosition(2,3)->widget());

    if(key->text() == "\010")
    {
            p->animateClick(150);
    }

        for(int i(0);i < 5;i++)
        {
            for(int j(0);j < 4;j++)
             {
                p = (QPushButton*)(lay->itemAtPosition(i+2,j+1)->widget());

                if(p->text()==key->text())
                {

                        p->animateClick(150);
                        break;
                }
              }
          }
}


void Calculator :: ButtonClicked()
{
    str = ((QPushButton*)sender())->text();




    if(str == " ")
    {
      str1[k].remove(str1[k].size()-1,1);
      num->display(str1[k].toDouble());
      if(symnum > 0)
      {
          symnum--;
      }

    }

    if(str == "C")
    {
        str1[k] = "";
        if(k == 1)
        {
            str1[k-1] = "";
        }
        else
        {
           str1[k+1] = "";
        }
        text->clear();
        num->display(str1[k].toDouble());
        symnum = 0;
    }

    if(str == "CE")
    {
        str1[k] = "";
        num->display(str1[k].toDouble());
        symnum = 0;
    }

    if(str.contains(QRegExp("[/,*,+,-]")))
    {

        text->setText(text->text() + str1[k] + str);
        if(k == 1)
        {
            k--;
            str1[k].setNum(Calculate());
            str1[k+1] = "";
            num->display(str1[k].toDouble());
        }
        k++;
        symnum = 0;
    }

    if(str == "=")
    {
        if(k == 1)
        {
            k--;
            QString a = text->text();
            str = a[a.size() - 1];
            str1[k].setNum(Calculate());
            num->display(str1[k]);
            text->clear();
            str = "";
            str1[k + 1] = "";
            symnum = 0;
        }
    }



    if(str.contains(QRegExp("[0-9,.]")))
    {
        if(symnum != 16)
        {
            str1[k].push_back(str);
            num->display(str1[k].toDouble());
            symnum++;
        }

    }
}

double Calculator::Calculate()
{

    if(str == "+")
    {
        return str1[k].toDouble() + str1[k+1].toDouble();
    }
    if(str == "-")
    {
        return str1[k].toDouble() - str1[k+1].toDouble();
    }
    if(str == "*")
    {
        return str1[k].toDouble() * str1[k+1].toDouble();
    }
    if(str == "/")
    {   if(str1[k+1] == "0")
        {
          return 1505;
        }
        else
        {
            return str1[k].toDouble() / str1[k+1].toDouble();
        }
    }
    if(str == "^")
    {
        double result = 1.0;

        for(int i(0);i < str1[k+1].toInt();i++)
        {
            result *= str1[k].toDouble();
        }
        return result;
    }

    return 0;
}
