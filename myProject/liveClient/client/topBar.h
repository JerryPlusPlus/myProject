#pragma once

#include<qwidget.h>
#include<qboxlayout.h>
#include<qlineedit.h>
#include<qframe.h>
#include<qpushbutton.h>


class topBar : QWidget
{
	Q_OBJECT

public:
	topBar(QWidget* parent = nullptr);
	~topBar();

private:
	QBoxLayout* topBarLayout;
	QFrame* statusFrame;
	QPushButton* backButton;
	QPushButton* refreshButton;
	/*QFrame* searchFrame;
	QPushButton* searchButton;
	QLineEdit* searchInput;*/

	QPushButton* littleRocket;
	QPushButton* startlive;
	QPushButton* message;
	QPushButton* gift;
	//Í·Ïñ
	QPushButton* unfold;
	QPushButton* min;
	QPushButton* max;
	QPushButton* close;

};

