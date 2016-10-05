#ifndef INTERFACE_H
#define INTERFACE_H


#include <QMainWindow>
#include <QMessageBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include <QString>
#include <string>

#include "vocalbulary.h"
#include "field.h"
#include "fieldgui.h"

namespace Ui {
class Interface;
}

class Interface : public QMainWindow, public Vocalbulary
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();

private slots:
    void Update();

    void on_generation_clicked();

    void on_addButton_clicked();

    void on_delButton_clicked();

private:
    Ui::Interface *ui;
};

#endif // INTERFACE_H
