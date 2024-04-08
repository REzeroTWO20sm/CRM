#include "../start_widget/start_widget.hpp"
#include "../diolog_add_guest/diolog_add_guest.hpp"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QtWidgets>
#include <QFormLayout>
#include <QObject>
#include <string>
#include "start_widget.hpp"

// void start_Widget::onAddGuestsButton_click(){
//     QPushButton *guest = new QPushButton;
// }

void start_Widget::addNewGuest(const QString& text){
    QPushButton *newButton = new QPushButton(text);
    guestsLayout->addWidget(newButton);
}

start_Widget::start_Widget(QWidget *parent) : QWidget(parent){

    guestsLayout = new QHBoxLayout;
    QPushButton *addGuestsButton = new QPushButton("+");

    guestsLayout->addWidget(addGuestsButton);

    // Создаем слот для обработки нажатия на кнопку addButton
    // QObject::connect(addGuestsButton, &QPushButton::clicked, [&] {
    //     QPushButton *newButton = new QPushButton("guest");
    //     guestsLayout->addWidget(newButton);
    // });

    connect(addGuestsButton, &QPushButton::clicked, [=] {
        diologAddGuests_Widget *diolog_window = new diologAddGuests_Widget;
        // Подключение сигнала кнопки нового окна к обработчику
        connect(diolog_window, &diologAddGuests_Widget::buttonAddClicked, this, [=](const QString& buttonText) {
            addNewGuest(buttonText);  // Вызов функции создания кнопки с переданным текстом
        });
        diolog_window->show();
    });
    
    // QObject::connect(addGuestsButton, &QPushButton::clicked, [&] {
    //     diologAddGuests_Widget *diolog_window = new diologAddGuests_Widget;  // Создание нового экземпляра окна
    //     diolog_window->show();  // Отображение нового окна
    // });

    setLayout(guestsLayout);
}