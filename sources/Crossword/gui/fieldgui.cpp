#include "fieldgui.h"

FieldGUI::FieldGUI(std::vector<std::vector<std::string>> field, QWidget *parent) :
    QMainWindow(parent)
{
    for(int i = 0; i < sizeField; i++)
    {
        for(int j = 0; j < sizeField; j++)
        {
            if(field[i][j] == " ")
            {
                QPushButton *b = new QPushButton(QString::fromStdString(field[i][j]),this);
                b->setStyleSheet("background-color: blue");
                b->setGeometry(QRect(QPoint((j*sizeButton), (i*sizeButton)), QSize(sizeButton, sizeButton)));
            }
            else
            {
                QPushButton *b = new QPushButton(QString::fromStdString(field[i][j]),this);
                b->setStyleSheet("background-color: white");
                b->setGeometry(QRect(QPoint((j*sizeButton), (i*sizeButton)), QSize(sizeButton, sizeButton)));
            }
        }
    }
    this->setMinimumSize(sizeButton*sizeField, sizeButton*sizeField);
}

FieldGUI::~FieldGUI()
{

}

