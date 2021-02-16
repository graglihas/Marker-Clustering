#include "dbconnectionform.h"
#include "ui_dbconnectionform.h"
#include <Track/trackreadfromdb.h>
#include <Track/Track.h>

DBConnectionForm::DBConnectionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBConnectionForm)
{
    ui->setupUi(this);
}

DBConnectionForm::~DBConnectionForm()
{
    delete ui;
}

void DBConnectionForm::on_pushButton_connect_clicked()
{
    TrackReadFromDb tdb;
    tdb.ConnectDB(ui->lineEdit_server->text(),ui->lineEdit_port->text().toInt());
    QList<Track> l;
    tdb.FetchAllData(l);
}
