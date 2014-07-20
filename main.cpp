#include <QCoreApplication>
#include "googleimage.h"
#include <QDebug>
//#include <QTimer>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QTimer t;

//    t.connect (&t, SIGNAL(timeout()), &a, SLOT(quit()));
//    t.start(4000);

    qDebug() << "====program begins!====";

    googleimage gimage(&a, argc,argv);

    gimage.accessJSON();

    return a.exec();
}
