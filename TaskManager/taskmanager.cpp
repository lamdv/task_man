#include "taskmanager.h"
#include "ui_taskmanager.h"
#include "warning.h"

TaskManager::TaskManager(QWidget *parent) : QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);
    int last_time;
    QDateTime current = QDateTime::currentDateTime();

//Set main win title
    setWindowTitle("Task Manager");

    //periodically refresh table

//    if(current.toTime_t() - last_time > 1)
//    {
        fillTable();
//        last_time = current.toTime_t();
//    }

      return;
}

void TaskManager::fillTable(){
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui -> tableWidget -> setColumnCount(11);
    QStringList title;
    title << "User" << "PID" << "CPU Usage" << "Memory Usage" << "VSZ" << "RSS" << "TTY" << "STAT" << "START" << "Running time" << "Command";
    ui -> tableWidget -> setHorizontalHeaderLabels(title);
    ui -> tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui -> tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    FILE *fp;
    char path[10000];

    /* Open the command for reading. */
    fp = popen("ps aux", "r");
    if (fp == NULL) {
        std::cout << "Failed to run command\n";
        exit(1);
    }

    /* Skip the first line */
    fgets(path, sizeof(path)-1, fp);

    /* Read the output a line at a time - output it. */
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        AddFile(path);
    }

      /* close */
      pclose(fp);
}

TaskManager::~TaskManager()
{
    delete ui;
}

//Set EndProcess button function
void TaskManager::on_endProcess_clicked()
{
    int res;
    QString command;
    QItemSelectionModel *select = ui->tableWidget->selectionModel();
    WARNING wn(this);

//Set sub win title
    wn.setWindowTitle("WARING !!!");

    res = wn.exec();

    if((res != QDialog::Rejected)&&(!select->selectedRows(1).isEmpty()))
    {
        command = "kill " + select->selectedRows(1).takeFirst().data().toString();
        system(command.toStdString().c_str());
        system("wait");

    }

    fillTable();
}

void TaskManager::AddFile(QString s){
    //Create row
        ui -> tableWidget -> insertRow(ui -> tableWidget -> rowCount());
        int file = ui -> tableWidget -> rowCount() - 1;

    QString t_user, t_tty, t_stat, t_start, t_time, t_cmd, t_cpu, t_mem;
    int t_id, t_vsz, t_rss;

    //get user
    QStringList mark = s.split(" ", QString::SkipEmptyParts);
    t_user = mark[0];

    //Get id
    t_id = mark[1].toInt();

    //Get cpu
    t_cpu = mark[2];

    //Get mem
    t_mem = mark[3];

    //Get vsz
    t_vsz = mark[4].toInt();

    //Get rss
    t_rss = mark[5].toInt();

    //Get TTY
    t_tty = mark[6];

    //Get STAT
    t_stat = mark[7];

    //Get START
//    s = s.substr(mark+1);
//    mark = s.split("\t");
//    t_start = s.substr(0,mark);
    t_start = mark[8];

    //Get time
//    s = s.substr(mark+1);
//    mark = s.split("\t");
//    t_time = s.substr(0,mark);
    t_time = mark[9];

    //Get command
//    s = s.substr(mark+1);
//    mark = s.split("\t");
//    t_cmd = s.substr(0,mark);
    t_cmd = mark[10];

    //Insert row
    ui -> tableWidget -> setItem(file, User, new QTableWidgetItem(t_user));
    ui -> tableWidget -> setItem(file, PID, new QTableWidgetItem(QString::number(t_id)));
    ui -> tableWidget -> setItem(file, CPU_Usage, new QTableWidgetItem(t_cpu));
    ui -> tableWidget -> setItem(file, Memory_Usage, new QTableWidgetItem(t_mem));
    ui -> tableWidget -> setItem(file, VSZ, new QTableWidgetItem(QString::number(t_vsz)));
    ui -> tableWidget -> setItem(file, RSS, new QTableWidgetItem(QString::number(t_rss)));
    ui -> tableWidget -> setItem(file, TTY, new QTableWidgetItem(t_tty));
    ui -> tableWidget -> setItem(file, STAT, new QTableWidgetItem(t_stat));
    ui -> tableWidget -> setItem(file, START, new QTableWidgetItem(t_start));
    ui -> tableWidget -> setItem(file, Running_time, new QTableWidgetItem(t_time));
    ui -> tableWidget -> setItem(file, Command, new QTableWidgetItem(t_cmd));
}
