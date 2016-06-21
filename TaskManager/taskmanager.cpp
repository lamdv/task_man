#include "taskmanager.h"
#include "ui_taskmanager.h"
#include "warning.h"

TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);

//Set table
    QStringList title;

//Set main win title
    setWindowTitle("Task Manager");

//Create table
    ui -> tableWidget -> setColumnCount(11);
    title << "User" << "PID" << "CPU Usage" << "Memory Usage" << "VSZ" << "RSS" << "TTY" << "STAT" << "START" << "Running time" << "Command";
    ui -> tableWidget -> setHorizontalHeaderLabels(title);

//Create row
    ui -> tableWidget -> insertRow(ui -> tableWidget -> rowCount());
    file = ui -> tableWidget -> rowCount() - 1;

//Show running processes in terminal
    FILE *fp;
    char path[1035];

    /* Open the command for reading. */
    fp = popen("ps aux", "r");
    if (fp == NULL) {
        cout << "Failed to run command\n";
        exit(1);
    }

    /* Read the output a line at a time - output it. */
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        void TaskManager::AddFile(string s){
            string t_user, t_tty, t_stat, t_start, t_time, t_cmd, t_cpu, t_mem;
            int t_id, t_vsz, t_rss;

            //get user
            s = s.substr(mark+1);
            mark = s.find("\t");
            t_user = s.substr(0,mark);

            //Get id
            int mark = s.find("\t");
            t_id = atoi(s.substr(0,mark).c_str());

            //Get cpu
            s = s.substr(mark+1);
            mark = s.find("\t");
            t_cpu = s.substr(0,mark);

            //Get mem
            s = s.substr(mark+1);
            mark = s.find("\t");
            t_mem = s.substr(0,mark);

            //Get vsz
            int mark = s.find("\t");
            t_vsz = atoi(s.substr(0,mark).c_str());

            //Get rss
            int mark = s.find("\t");
            t_rss = atoi(s.substr(0,mark).c_str());

            //Get TTY
            s = s.substr(mark+1);
            mark = s.find("\t");
            t_tty = s.substr(0,mark);

            //Get STAT
            s = s.substr(mark+1);
            mark = s.find("\t");
            t_stat = s.substr(0,mark);

            //Get START
            s = s.substr(mark+1);
            mark = s.find("\t");
            t_start = s.substr(0,mark);

            //Get time
            s = s.substr(mark+1);
            mark = s.find("\t");
            t_time = s.substr(0,mark);

            //Get command
            s = s.substr(mark+1);
            mark = s.find("\t");
            t_cmd = s.substr(0,mark);
        }
    }

      /* close */
      pclose(fp);

      return 0;
}

TaskManager::~TaskManager()
{
    delete ui;
}

//Set EndProcess button function
void TaskManager::on_endProcess_clicked()
{
    int res;
    WARNING wn(this);

//Set sub win title
    wn.setWindowTitle("WARING !!!");

    res = wn.exec();

//If cancel kill
    if(res == QDialog::Rejected)
        return;
}
