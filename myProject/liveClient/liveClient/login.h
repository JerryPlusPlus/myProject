#pragma once
#include<qwidget.h>
#include<qlineedit.h>
#include<qpushbutton.h>
#include<qlabel.h>
#include<qboxlayout.h>

#include<qsqldatabase.h>
#include<qsqlquery.h>
#include<qsqlerror.h>

#include<qpixmap.h>

class CircleIconWidget : public QPushButton {
	Q_OBJECT

public:
	CircleIconWidget(QWidget* parent = nullptr);
	void setIcon(const QString& path);

protected:
	void paintEvent(QPaintEvent* event) override;

private:
	QPixmap icon;
};



class Login : public QWidget {

	Q_OBJECT

public:
	Login(QWidget* parent = nullptr);
	~Login();

protected:
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

private:
	QWidget* leftPart;
	QWidget* rightPart;
	QFrame* splitterLine;
	QBoxLayout* loginLayout;


	QLabel* scanLabel;
	QLabel* scanImage;
	QFrame* leftThread;
	QLabel* anotherWayLabel;
	QFrame* rightThread;
	CircleIconWidget* qqLogin;
	CircleIconWidget* wechatLogin;
	CircleIconWidget* weboLogin;


	QLabel* messageLogin;
	QLabel* accountLogin;
	QLineEdit* pass1;
	QFrame* pass1Line;
	QLineEdit* pass2;
	QFrame* pass2Line;
	QLineEdit* pass3;
	QPushButton* loginButton;
	QLabel* agreeText;
	QPushButton* fastRegisterButton;


	QSqlDatabase* db;
	QPoint z;

private slots:
	void login();
	void registerUser();

};

