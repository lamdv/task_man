#ifndef WARNING_H
#define WARNING_H

#include <QDialog>

namespace Ui {
class WARNING;
}

class WARNING : public QDialog
{
    Q_OBJECT

public:
    explicit WARNING(QWidget *parent = 0);
    ~WARNING();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::WARNING *ui;
};

#endif // WARNING_H
