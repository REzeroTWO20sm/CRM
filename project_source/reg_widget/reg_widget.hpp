#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QtWidgets>
#include <QFormLayout>
#include <QObject>
#include <string>
#include <QGroupBox>

class reg_Widget : public QWidget{
    Q_OBJECT
public:
    reg_Widget(QWidget *parent = nullptr);

public slots:
    void onButtonClickedLogin();
    void onButtonClickedPassword();

private:
    QLineEdit *loginEdit;
    QLineEdit *passwordEdit;
};