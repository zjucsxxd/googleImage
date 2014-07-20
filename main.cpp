#include <QCoreApplication>
#include "googleimage.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    googleimage gimage(argc,argv);

    gimage.accessJSON();

    return a.exec();
}
