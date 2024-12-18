#include <QtWidgets/QApplication>
#include<qtranslator.h>
#include<qicon.h>
#include<qfile.h>
#include "stdafx.h"
#include "mainInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icon/images/huya.svg"));
    QTranslator translator;
	if (translator.load(R"(zh.qm)"))
	{
		a.installTranslator(&translator);
	}
    QFile qss(":/QSS/login.qss");
    qss.open(QFile::ReadOnly);
	a.setStyleSheet(qss.readAll());
	qss.close();

    mainInterface w;
    //w.show();
    return a.exec();
}
