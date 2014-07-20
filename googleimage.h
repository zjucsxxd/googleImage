#ifndef GOOGLEIMAGE_H
#define GOOGLEIMAGE_H

#include <QObject>

class QString;
class QNetworkReply;
class QNetworkAccessManager;
class QCoreApplication;

class googleimage : public QObject
{
    Q_OBJECT
public:
//    googleimage(int argc, char* argv[]);
    googleimage(QCoreApplication*, int , char* []);
    ~googleimage();

    googleimage& accessJSON();

signals:
    void myTimeout();

public slots:
    void downloadJSON(QNetworkReply*);
    void downloadFile(QNetworkReply*);

private:
//  wordname,, word,,
//  worddirectory,, directory to store image of word,,
    QString wordName, wordDirectory;

    QString apiUrl, fileUrl;

//  initialName,,
    void initialName(int argc, char *argv[]);

//  urlaccsss,,
    QNetworkAccessManager* jsonAccess, * urlAccess;
};

#endif // GOOGLEIMAGE_H
