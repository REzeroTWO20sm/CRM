#include "../reg_widget/reg_widget.hpp"

void reg_Widget::onButtonClickedLogin() {
    QString text = loginEdit->text();
    qDebug() << "Writen Login was: " << text;
}

void reg_Widget::onButtonClickedPassword() {
    QString text = passwordEdit->text();
    qDebug() << "Writen Password was: " << text;
}

reg_Widget::reg_Widget(QWidget *parent) : QWidget(parent){
    loginEdit = new QLineEdit;
    passwordEdit = new QLineEdit;

    QHBoxLayout *mainLayout = new QHBoxLayout;
    QGroupBox* groupBox = new QGroupBox;
    QHBoxLayout *imageLayout = new QHBoxLayout;
    QVBoxLayout *regLayout = new QVBoxLayout;
    
    QLabel *image_lable = new QLabel;
    QPixmap image("/home/robert/CRM/images/wid.png");
    QPixmap scaledImage2 = image.scaled(1000,1000, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QLabel *autorization_text = new QLabel("AUTORIZATION");
    //QLineEdit *loginLineEdit = new QLineEdit;
    //reg_Widget *loginLindEdit_reg_Widget_ptr = new reg_Widget{loginLineEdit};
    //loginLindEdit_reg_Widget_ptr->setlineEdit(loginLineEdit);
    //QLineEdit reg_Widget::loginLine;

    //QLineEdit *passwordLineEdit = new QLineEdit;
    //reg_Widget *passwordLineEdit_reg_Widget_ptr = new reg_Widget{passwordLineEdit};

    QPushButton *autorizationButton = new QPushButton("ENTER");

    regLayout->setSpacing(30);
    regLayout->addWidget(autorization_text);
    regLayout->addWidget(loginEdit);
    regLayout->addWidget(passwordEdit);
    regLayout->addWidget(autorizationButton);
    regLayout->setAlignment(autorizationButton,Qt::AlignCenter);


    autorization_text->setStyleSheet("color: #B2B2B2;font: bold 28pt; letter-spacing: 7px;font-family:monospace;");
    autorization_text->setAlignment(Qt::AlignCenter);

    loginEdit->setMinimumHeight(60);
    loginEdit->setPlaceholderText("login");
    loginEdit->setStyleSheet(
        "QLineEdit { selection-background-color: #444444;color:#6A6C6A;background-color: #292929;border: 2px dashed #252525;font-family: monospace; font-size: 18pt; }"
        "QLineEdit:focus { color:#B2B2B2;background-color: #2C2C2C; border: 2px dashed #444444; border-radius: 4px;}"
    );
    loginEdit->setAlignment(Qt::AlignCenter);

    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setMinimumHeight(60);
    passwordEdit->setPlaceholderText("password");
    passwordEdit->setStyleSheet(
        "QLineEdit { selection-background-color: #444444;color:#6A6C6A;background-color: #292929;border: 2px dashed #252525;font-family: monospace; font-size: 18pt; }"
        "QLineEdit:focus { color:#B2B2B2;background-color: #2C2C2C; border: 2px dashed #444444; border-radius: 4px;}"
    );
    passwordEdit->setAlignment(Qt::AlignCenter);

    autorizationButton->setMinimumHeight(60);
    autorizationButton->setMinimumWidth(200);
    autorizationButton->setStyleSheet(
        "QPushButton {letter-spacing: 1px;font-family:monospace; font-size: 16pt; color: #A0A0A0}"
        "QPushButton:pressed { color: white; }"
    );
    
    //connect(autorizationButton, SIGNAL, SLOT(onButtonClicked()));
    connect(autorizationButton,&QPushButton::clicked, this,&reg_Widget::onButtonClickedLogin);
    connect(autorizationButton,&QPushButton::clicked, this,&reg_Widget::onButtonClickedPassword);
    //QObject::connect(autorizationButton, SIGNAL(clicked()),passwordLineEdit_reg_Widget_ptr, SLOT(onButtonClickedPassword()));

    imageLayout->addLayout(regLayout);
    imageLayout->setAlignment(regLayout,Qt::AlignCenter);

    groupBox->setLayout(imageLayout);
    groupBox->setAlignment(Qt::AlignCenter);

    image_lable->setPixmap(scaledImage2);
    mainLayout->addWidget(image_lable);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(groupBox);
    
    setLayout(mainLayout);
}
