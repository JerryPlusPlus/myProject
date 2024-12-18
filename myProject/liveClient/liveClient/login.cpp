#include<qdebug.h>
#include<qboxlayout.h>
#include<qfile.h>
#include<qpushbutton.h>
#include<qcryptographichash.h>
#include<qbytearray.h>
#include<qpainter.h>
#include<qpainterpath.h>
#include"stdafx.h"
#include"login.h"


CircleIconWidget::CircleIconWidget(QWidget* parent)
	: QPushButton(parent) {
	setFixedSize(30, 30);  // 设置控件的固定大小
}

void CircleIconWidget::setIcon(const QString& path) {
	icon.load(path);
	update();  // 重新绘制控件
}

void CircleIconWidget::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	// 绘制圆形
	QPainterPath path;
	path.addEllipse(rect());
	painter.setClipPath(path);

	// 绘制图标
	if (!icon.isNull()) {
		painter.drawPixmap(rect(), icon);
	}
}


Login::Login(QWidget* parent) {

	resize(712, 410);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
	/*QPalette palette = this->palette();	// 设置login窗口背景颜色
	palette.setColor(QPalette::Window, QColor("#282828"));
	this->setPalette(palette);*/

	leftPart = new QWidget(this);
	leftPart->resize(291, 410);
	rightPart = new QWidget(this);
	rightPart->resize(420, 410);
	// 创建一条竖着的细线
	splitterLine = new QFrame(this);
	splitterLine->setFrameShape(QFrame::VLine);
	splitterLine->setFrameShadow(QFrame::Sunken);
	loginLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);
	loginLayout->addWidget(leftPart);
	loginLayout->addWidget(splitterLine);
	loginLayout->addWidget(rightPart);



#pragma region leftPart in login
	QBoxLayout* leftLayout = new QBoxLayout(QBoxLayout::TopToBottom, leftPart);
	QBoxLayout* otherWayTextLayout = new QBoxLayout(QBoxLayout::LeftToRight);
	QBoxLayout* otherWayIconLayout = new QBoxLayout(QBoxLayout::LeftToRight);

	scanLabel = new QLabel(tr("please use huyaApp scan the QR code to login"), leftPart);
	scanImage = new QLabel(leftPart);
	QPixmap pixmap(":/left_part/images/QRcode.png");
	scanImage->setPixmap(pixmap);
	leftThread = new QFrame(leftPart);
	leftThread->setFrameShape(QFrame::HLine);
	leftThread->setFrameShadow(QFrame::Sunken);
	anotherWayLabel = new QLabel(tr("Another way to login"), leftPart);
	rightThread = new QFrame(leftPart);
	rightThread->setFrameShape(QFrame::HLine);
	rightThread->setFrameShadow(QFrame::Sunken);
	qqLogin = new CircleIconWidget(leftPart);
	qqLogin->setIcon(":/left_part/images/qq.png");
	wechatLogin = new CircleIconWidget(leftPart);
	wechatLogin->setIcon(":/left_part/images/wechat.png");
	weboLogin = new CircleIconWidget(leftPart);
	weboLogin->setIcon(":/left_part/images/weibo.png");

	otherWayTextLayout->addWidget(leftThread);
	otherWayTextLayout->addWidget(anotherWayLabel);
	otherWayTextLayout->addWidget(rightThread);

	otherWayIconLayout->addWidget(qqLogin);
	otherWayIconLayout->addWidget(wechatLogin);
	otherWayIconLayout->addWidget(weboLogin);

	leftLayout->addWidget(scanLabel);
	leftLayout->addWidget(scanImage);
	leftLayout->addLayout(otherWayTextLayout);
	leftLayout->addLayout(otherWayIconLayout);
	leftLayout->setSpacing(10);


	connect(qqLogin, &QPushButton::clicked, this, [this]() {
		qDebug() << "QQ Login icon clicked";  // 添加调试输出
		QWidget* anotherWayLogin = new QWidget(this);  // 设置父窗口为 nullptr
		anotherWayLogin->setAttribute(Qt::WA_DeleteOnClose);  // 窗口关闭时自动删除
		anotherWayLogin->setWindowTitle(tr("Another way to login"));
		anotherWayLogin->resize(300, 200);  // 设置窗口大小
		anotherWayLogin->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);  // 设置窗口标志
		anotherWayLogin->show();
		});


	/*connect(wechatLogin, &QPushButton::clicked, this, &Login::anotherWayLoginClicked);
	connect(weboLogin, &QPushButton::clicked, this, &Login::anotherWayLoginClicked);*/

#pragma endregion



#pragma region rightPart in login
	QBoxLayout* rightLayout = new QBoxLayout(QBoxLayout::TopToBottom, rightPart);
	QBoxLayout* loginTextLayout = new QBoxLayout(QBoxLayout::LeftToRight);


	messageLogin = new QLabel(tr("messageLogin"), rightPart);
	accountLogin = new QLabel(tr("accountLogin"), rightPart);
	pass1 = new QLineEdit(rightPart);
	pass1Line = new QFrame(rightPart);
	pass1Line->setFrameShape(QFrame::HLine);
	pass1Line->setFrameShadow(QFrame::Sunken);
	pass2 = new QLineEdit(rightPart);
	pass2Line = new QFrame(rightPart);
	pass2Line->setFrameShape(QFrame::HLine);
	pass2Line->setFrameShadow(QFrame::Sunken);
	pass3 = new QLineEdit(rightPart);
	loginButton = new QPushButton(tr("login"), rightPart);
	agreeText = new QLabel(tr("agreeText....................."), rightPart);
	fastRegisterButton = new QPushButton(tr("fast register"), rightPart);

	loginTextLayout->addWidget(messageLogin);
	loginTextLayout->addWidget(accountLogin);

	rightLayout->addLayout(loginTextLayout);
	rightLayout->addWidget(pass1);
	rightLayout->addWidget(pass1Line);
	rightLayout->addWidget(pass2);
	rightLayout->addWidget(pass2Line);
	rightLayout->addWidget(pass3);
	rightLayout->addWidget(loginButton);
	rightLayout->addWidget(agreeText);
	rightLayout->addWidget(fastRegisterButton);

	connect(loginButton, &QPushButton::clicked, this, &Login::login);
	connect(fastRegisterButton, &QPushButton::clicked, this, &Login::registerUser);

#pragma endregion



#pragma region login user checked and register information added
	db = new QSqlDatabase(QSqlDatabase::addDatabase("QODBC"));
	db->setDatabaseName("Ubuntu_mysql");
	db->setUserName("root");
	db->setPassword("123456");

	if (!db->open()) {	//测试数据库连接是否成功
		qDebug() << "Failed to connect to database:" << db->lastError().text();
	}
	else {
		qDebug() << "Connected to database successfully!";
	}

#pragma endregion
}





void Login::login() {
	/*QString username = userName->text();
	QString pwd = passWord->text();

	QByteArray hash = QCryptographicHash::hash(pwd.toUtf8(), QCryptographicHash::Sha256);
	QSqlQuery query;
	query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
	query.bindValue(":username", username);
	query.bindValue(":password", hash.toHex());
	if (query.exec()) {
		if (query.next()) {
			qDebug() << "Login successful!";
		}
		else {
			qDebug() << "Login failed: Invalid username or password!";
		}
	}
	else {
		qDebug() << "Login failed:" << query.lastError().text();
	}*/

	qDebug() << "login button clicked";
}

void Login::registerUser() {
	/*QString username = userName->text();
	QString pwd = passWord->text();
	QByteArray hash = QCryptographicHash::hash(pwd.toUtf8(), QCryptographicHash::Sha256);
	QSqlQuery query;
	query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
	query.bindValue(":username", username);
	query.bindValue(":password", hash.toHex());
	if (query.exec()) {
		qDebug() << "User registered successfully!";
	}
	else {
		qDebug() << "Registration failed:" << query.lastError().text();
	}*/
	qDebug() << "register button clicked";

}





Login::~Login() {

	db->close();

}

void Login::mouseMoveEvent(QMouseEvent* event) {
	QWidget::mouseMoveEvent(event);
	QPoint y = event->globalPosition().toPoint();	//鼠标相当于桌面左上角的位置，鼠标全局位置
	QPoint x = y - z;

	this->move(x);
}

void Login::mousePressEvent(QMouseEvent* event) {
	QWidget::mousePressEvent(event);
	QPoint y = event->globalPosition().toPoint();//鼠标相当于桌面左上角的位置，鼠标全局位置
	QPoint x = this->geometry().topLeft();//窗口左上角相对于桌面左上角的位置，窗口位置
	this->z = y - x;	//定值，不变的
	//z = event->globalPos() - this->frameGeometry().topLeft();

}

void Login::mouseReleaseEvent(QMouseEvent* event) {
	QWidget::mouseReleaseEvent(event);
	this->z = QPoint();//鼠标松开的时候，将z值初始化。
}