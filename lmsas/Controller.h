#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QList>

class Controller:public QObject
{
public:

    virtual bool Create(QList<QObject>&)=0;
    virtual bool Update(QList<QObject>&)=0;
    virtual bool Delete(QList<QObject>&)=0;
    virtual bool Export(QList<QObject>&)=0;
    virtual bool Save(QList<QObject>&)=0;

    virtual ~Controller();
protected:
    Controller();
};

#endif // CONTROLLER_H


