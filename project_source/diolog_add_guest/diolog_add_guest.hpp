#pragma once 

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

class diologAddGuests_Widget : public QWidget{
    Q_OBJECT
public:
    diologAddGuests_Widget(QWidget *parent = nullptr);

signals:
    void buttonAddClicked(const QString& buttonText);
private:
    QHBoxLayout *layout;
};