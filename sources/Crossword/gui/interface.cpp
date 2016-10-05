#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);

    QRegExp reg("[a-z]{1,20}");
    ui->lineEdit->setValidator(new QRegExpValidator(reg, this));
}

Interface::~Interface()
{
    delete ui;
}

void Interface::Update()
{
    QString outputWords;
    for(std::vector<std::string>::iterator i = words.begin(); i < words.end(); i++)
        outputWords = outputWords + QString::fromStdString(*i) + "\n";

    ui->textEdit->setText(outputWords);
}

void Interface::on_generation_clicked()
{
    Field *field = new Field();
    FieldGUI *fieldGui = new FieldGUI(field->Generation(Output()));
    fieldGui->show();
}

void Interface::on_addButton_clicked()
{
    AddWord(ui->lineEdit->text().toStdString());
    ui->lineEdit->clear();
    this->Update();
}

void Interface::on_delButton_clicked()
{
    DelWord(ui->lineEdit->text().toStdString());
    ui->lineEdit->clear();
    this->Update();
}
