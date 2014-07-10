#include <QDebug>
#include "socketework.h"

SocketWork::SocketWork(QObject *parent)
    : QObject(parent)
    , hasConnection(false)
{
}

void SocketWork::doConnection()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("google.com.br", 80);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting...";
    while(!socket->waitForConnected());

    if(hasConnection && !socket->waitForDisconnected())
        qDebug() << "Error: " << socket->errorString();
}

void SocketWork::connected()
{
    qDebug() << "Ok, we have a connection";
    hasConnection = true;
    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void SocketWork::disconnected()
{
    qDebug() << "Disconnected...";
}

void SocketWork::read()
{
    qDebug() << "Reading...";
    qDebug() << socket->readAll();
}

void SocketWork::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
}
