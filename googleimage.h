#ifndef GOOGLEIMAGE_H
#define GOOGLEIMAGE_H

#include <QObject>

class QString;
class QNetworkReply;
class QNetworkAccessManager;

class googleimage : public QObject
{
    Q_OBJECT
public:
    googleimage(int argc, char* argv[]);
    ~googleimage();

    googleimage& accessJSON();

signals:

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
