#pragma once

#include <QWidget>
#include <vector>
#include <QPushButton>
#include <QHBoxLayout>

class start_Widget : public QWidget{
    Q_OBJECT
public:
    start_Widget(QWidget *parent = nullptr);

//public slots:
    //void onAddGuestsButton_click();

private:
    QHBoxLayout *guestsLayout; // для новых кнопок гостей
    void addNewGuest(const QString& text);

    //std::vector<QPushButton*> *guests_vec;
    //QPushButton *guest;

    // QPushButton *button = new QPushButton;
    // std::vector<QPushButton*> hello {button};
};