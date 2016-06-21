#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QWidget>
#include <iostream>
#include <qdatetime.h>

namespace Ui {
class TaskManager;
}

class TaskManager : public QWidget
{
    Q_OBJECT

public:
    explicit TaskManager(QWidget *parent = 0);
    ~TaskManager();
    void AddFile(QString s);
    void fillTable();

private slots:
    void on_endProcess_clicked();

private:
    Ui::TaskManager *ui;

    enum Colume {
        User, PID, CPU_Usage, Memory_Usage, VSZ, RSS, TTY, STAT, START, Running_time, Command
    };
};

#endif // TASKMANAGER_H
