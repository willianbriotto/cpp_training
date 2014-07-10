#ifndef SOCKETEWORK_H
#define SOCKETEWORK_H

#include <QObject>
#include <QTcpSocket>

class SocketWork : public QObject
{
    Q_OBJECT
public:
    SocketWork(QObject *parent = 0);
    void doConnection();

public slots:
    void connected();
    void disconnected();
    void read();
    void bytesWritten(qint64);

private:
    QTcpSocket *socket;
    bool hasConnection;
};

#endif // SOCKETEWORK_H
