#include "adder.h"
#include "ui_adder.h"

Adder::Adder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adder)
{
    ui->setupUi(this);
    connect(ui->equ,
            SIGNAL(clicked()),
            this,SLOT(jisuan()));
}

Adder::~Adder()
{
    delete ui;
}
void   Adder::jisuan(){
    ui->res->setText(QString::number(
        ui->add->text().toInt()+
        ui->added->text().toInt()));
}


