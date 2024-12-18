#pragma once
#include<qwidget.h>
#include<qpushbutton.h>


class leftGuide :public QWidget
{
	Q_OBJECT
public:
	leftGuide(QWidget* parent = nullptr);
	~leftGuide();

private:
	QPushButton* leftGuideButton;
};