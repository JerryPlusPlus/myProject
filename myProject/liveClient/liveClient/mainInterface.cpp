#include "stdafx.h"
#include "mainInterface.h"
#include"login.h"


mainInterface::mainInterface(QWidget *parent)
    : QMainWindow(parent)
{
	this->resize(800, 600);
	this->setWindowTitle(tr("huya Client"));
	//this->setWindowTitle("huya Client");
	//setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);	//ɾ��������

	Login* loginwidget = new Login(this);
	loginwidget->show();

	

}

mainInterface::~mainInterface()
{
   
}
