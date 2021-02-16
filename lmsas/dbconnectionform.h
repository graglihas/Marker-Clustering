#ifndef DBCONNECTIONFORM_H
#define DBCONNECTIONFORM_H

#include <QWidget>

namespace Ui {
class DBConnectionForm;
}

class DBConnectionForm : public QWidget
{
    Q_OBJECT

public:
    explicit DBConnectionForm(QWidget *parent = 0);
    ~DBConnectionForm();


private slots:
    void on_pushButton_connect_clicked();

private:
    Ui::DBConnectionForm *ui;
};

#endif // DBCONNECTIONFORM_H
