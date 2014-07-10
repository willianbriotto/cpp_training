#include <QCoreApplication>
#include "socketework.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SocketWork socketConnection;
    socketConnection.doConnection();
    
    return a.exec();
}
