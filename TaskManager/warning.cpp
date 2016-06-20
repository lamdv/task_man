#include "warning.h"
#include "ui_warning.h"

WARNING::WARNING(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WARNING)
{
    ui->setupUi(this);
}

WARNING::~WARNING()
{
    delete ui;
}

void WARNING::on_buttonBox_accepted()
{
    accept();
}

void WARNING::on_buttonBox_rejected()
{
    reject();
}
