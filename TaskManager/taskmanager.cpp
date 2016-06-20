#include "taskmanager.h"
#include "ui_taskmanager.h"
#include "warning.h"

TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);
    QStringList title;
    setWindowTitle("Task Manager");
    ui -> tableWidget -> setColumnCount(6);
    title << "Name" << "PID" << "CPU Usage" << "Memory Usage" << "Running time" << "Owner";
    ui -> tableWidget -> setHorizontalHeaderLabels(title);
}

TaskManager::~TaskManager()
{
    delete ui;
}
void TaskManager::on_endProcess_clicked()
{
    int res;
    WARNING wn(this);
    wn.setWindowTitle("WARING !!!");
    res = wn.exec();

    if(res == QDialog::Rejected)
        return;

    ui -> tableWidget -> insertRow(ui -> tableWidget -> rowCount());
}
