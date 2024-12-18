#pragma once
#include<qwidget.h>
#include<qpushbutton.h>


class centerContainer :public QWidget
{
	Q_OBJECT
public:
	centerContainer(QWidget* parent = nullptr);
	~centerContainer();

private:
	QPushButton* centerContainerButton;
};