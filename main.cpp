#include <QCoreApplication>
#include <QHostInfo>
#include <QHostAddress>
#include <QScopedPointer>
#include <dns_sd.h>
#include "bonjourregister.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QHostInfo hostInfo;
    hostInfo = QHostInfo::fromName(QHostInfo::localHostName());
    QString hostName = QHostInfo::localHostName();
    QScopedPointer<BonjourRegister> bonjour(new BonjourRegister());
    if (bonjour.data())
    {
        QByteArray dummy;
        int port =  54350;
        QByteArray name("Mango is Running on ");
        name.append(hostName);
        bonjour->Register(port, "_mangoes-responder._tcp",
                          name, dummy);
    }else{
        qDebug() << "There is no data in the register";
    }
    return a.exec();
}
