#ifndef FIELDGUI_H
#define FIELDGUI_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include <QString>
#include <string>
#include <vector>

#include "field.h"

namespace Ui {
class FieldGUI;
}

class FieldGUI : public QMainWindow, public Field
{
    Q_OBJECT

public:
    explicit FieldGUI(std::vector<std::vector<std::string> > field, QWidget *parent = 0);
    ~FieldGUI();
private:
    int sizeButton = 30;


};

#endif // FIELDGUI_H
