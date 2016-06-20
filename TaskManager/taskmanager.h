#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QWidget>

namespace Ui {
class TaskManager;
}

class TaskManager : public QWidget
{
    Q_OBJECT

public:
    explicit TaskManager(QWidget *parent = 0);
    ~TaskManager();

private slots:
    void on_endProcess_clicked();

private:
    Ui::TaskManager *ui;
};

#endif // TASKMANAGER_H
