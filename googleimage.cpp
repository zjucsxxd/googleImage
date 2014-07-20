#include "googleimage.h"
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QByteArray>

googleimage::googleimage(int argc, char *argv[])
{
    initialName(argc, argv);

    jsonAccess = new QNetworkAccessManager;
    urlAccess = new QNetworkAccessManager;

    connect( jsonAccess, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(downloadJSON(QNetworkReply*)));
    connect( urlAccess, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(downloadFile(QNetworkReply*)));
}

googleimage::~googleimage()
{
    delete jsonAccess;
    delete urlAccess;
}

googleimage &googleimage::accessJSON()
{
    jsonAccess -> get(QNetworkRequest(QUrl(apiUrl)));
    return *this;
}

void googleimage::downloadJSON(QNetworkReply* reply)
{
    QString jsonContent = QString (reply -> readAll() );
    QStringList contList = jsonContent.split(",");

    QStringList effectInfor;

    foreach(QString item, contList){
        if(item.indexOf("url") == +1){
            effectInfor = item.split("\"");
            fileUrl = effectInfor[3];
            qDebug() << fileUrl;
            urlAccess -> get(QNetworkRequest(QUrl(fileUrl)));
            break;
        }
    }

}

void googleimage::downloadFile(QNetworkReply* reply)
{
    QString outName = wordDirectory + "/" + wordName;
    QFile mfile(outName);
    if(!mfile.open(QFile::WriteOnly)){
        qDebug() << "Error!!";
        return;
    }

    QByteArray tStream;
    tStream=reply->readAll();
    mfile.write(tStream);
    mfile.flush();
    mfile.close();

}

void googleimage::initialName(int argc, char* argv[]) {
    wordName = argv[1];
    wordDirectory = argv[2];
    apiUrl = "https://ajax.googleapis.com/ajax/services/search/images?v=1.0&q=" + wordName;
}
