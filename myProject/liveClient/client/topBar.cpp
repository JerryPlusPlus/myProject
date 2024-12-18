#include "topBar.h"


topBar::topBar(QWidget* parent = nullptr)
	: QWidget(parent)
{
	statusFrame = new QFrame(this);
	statusFrame->setFixedSize(100, 40);
	statusFrame->setStyleSheet("QFrame{background-color: #2E2E2E; border-radius: 20px;}");

	backButton = new QPushButton(this);
	refreshButton = new QPushButton(this);

	littleRocket = new QPushButton(this);
	startlive = new QPushButton(this);
	message = new QPushButton(this);
	gift = new QPushButton(this);
	unfold = new QPushButton(this);
	min = new QPushButton(this);
	max = new QPushButton(this);
	close = new QPushButton(this);
}

topBar::~topBar()
{

}