

#ifndef login1_H
#define login1_H


#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>



class login1 : public QObject
{
    Q_OBJECT


public:
    login1( const QString &user, const QString &pass,const QString &host, int port = 465, int timeout = 1000000000 );
    ~login1();

    void sendMail( const QString &from, const QString &to, const QString &subject, const QString &body );

signals:
    void status( const QString &);

private slots:
    void stateChanged(QAbstractSocket::SocketState socketState);
    void errorReceived(QAbstractSocket::SocketError socketError);
    void disconnected();
    void connected();
    void readyRead();

private:
    int timeout;
    QString message;
    QTextStream *t;
    QSslSocket *socket;
    QString from;
    QString rcpt;
    QString response;
    QString user;
    QString pass;
    QString host;
    int port;
    enum states{Tls, HandShake ,Auth,User,Pass,Rcpt,Mail,Data,Init,Body,Quit,Close};
    int state;

};
#endif