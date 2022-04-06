#ifndef ONEFILE_H
#define ONEFILE_H

#include <QString>
//
struct OneFile{
    QString nameOnScreen;
    QString filename;
    OneFile(QString _nameOnScreen, QString _filename )
    {
        nameOnScreen = _nameOnScreen;
        filename = _filename;
    }
};

#endif // ONEFILE_H
