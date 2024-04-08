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
#include <QStackedWidget>
#include <QGridLayout>
#include "start_widget.hpp"

// void start_Widget::onAddGuestsButton_click(){
//     QPushButton *guest = new QPushButton;
// }

void start_Widget::addNewGuest(const QString& text){
    QPushButton *newButton = new QPushButton(text);
    guestsLayout->addWidget(newButton);
}

start_Widget::start_Widget(QWidget *parent) : QWidget(parent){

    QVBoxLayout *mainLayout = new QVBoxLayout;

    guestsLayout = new QHBoxLayout;
    QPushButton *addGuestsButton = new QPushButton("+");

    guestsLayout->addWidget(addGuestsButton);

    connect(addGuestsButton, &QPushButton::clicked, [=] {
        diologAddGuests_Widget *diolog_window = new diologAddGuests_Widget;
        // Подключение сигнала кнопки нового окна к обработчику
        connect(diolog_window, &diologAddGuests_Widget::buttonAddClicked, this, [=](const QString& buttonText) {
            addNewGuest(buttonText);  // Вызов функции создания кнопки с переданным текстом
        });
        diolog_window->show();
    });

    mainLayout->addLayout(guestsLayout);

    QHBoxLayout *dish_category_layout = new QHBoxLayout;

    QStackedWidget *dish_guest_stack = new QStackedWidget;
    QWidget *guest_1_widget = new QWidget;
    QHBoxLayout *guest_things_layout = new QHBoxLayout;
    QGridLayout *names_grid = new QGridLayout;
    guest_things_layout->addLayout(names_grid);
    guest_things_layout->setAlignment(names_grid,Qt::AlignTop);
    QLabel *name_label = new QLabel("Name: ");
    QLabel *count_label = new QLabel("Count: ");
    QLabel *price_label = new QLabel("Price: ");
    QLabel *sun_label = new QLabel("Sum: ");
    names_grid->addWidget(name_label,0,0);
    names_grid->addWidget(count_label,0,1);
    names_grid->addWidget(price_label,0,2);
    names_grid->addWidget(sun_label,0,3);

    dish_guest_stack->addWidget(guest_1_widget);
    
    guest_1_widget->setMinimumSize(200, 200);
    guest_1_widget->setLayout(guest_things_layout);

    QStackedWidget *categoryWidget_stack = new QStackedWidget;
    //layout_ghg->addLayout(guestsLayout);
    dish_category_layout->addWidget(dish_guest_stack);
    dish_category_layout->addWidget(categoryWidget_stack);

    mainLayout->addLayout(dish_category_layout);

    QWidget *category_widget = new QWidget;
    QGridLayout *category_grid = new QGridLayout;

    QPushButton *back1 = new QPushButton("back");
    QPushButton *back2 = new QPushButton("back");
    QPushButton *back3 = new QPushButton("back");
    QPushButton *back4 = new QPushButton("back");

    QPushButton *category_1_btn = new QPushButton("Salat");
    QPushButton *category_2_btn = new QPushButton("Hot");
    QPushButton *category_3_btn = new QPushButton("Coffee");
    QPushButton *category_4_btn = new QPushButton("Tea");
    category_grid->addWidget(category_1_btn,0,0);
    category_grid->addWidget(category_2_btn,0,1);
    category_grid->addWidget(category_3_btn,0,2);
    category_grid->addWidget(category_4_btn,1,0);

    category_widget->setLayout(category_grid);
    categoryWidget_stack->addWidget(category_widget);
    

    QWidget *dish_category_1_widget = new QWidget;
    categoryWidget_stack->addWidget(dish_category_1_widget);
    QGridLayout *dish_grid_1 = new QGridLayout;
    dish_category_1_widget->setLayout(dish_grid_1);

    QWidget *dish_category_2_widget = new QWidget;
    categoryWidget_stack->addWidget(dish_category_2_widget);
    QGridLayout *dish_grid_2 = new QGridLayout;
    dish_category_2_widget->setLayout(dish_grid_2);

    QWidget *dish_category_3_widget = new QWidget;
    categoryWidget_stack->addWidget(dish_category_3_widget);
    QGridLayout *dish_grid_3 = new QGridLayout;
    dish_category_3_widget->setLayout(dish_grid_3);

    QWidget *dish_category_4_widget = new QWidget;
    categoryWidget_stack->addWidget(dish_category_4_widget);
    QGridLayout *dish_grid_4 = new QGridLayout;
    dish_category_4_widget->setLayout(dish_grid_4);


    QPushButton *dish_1_category_1_btn = new QPushButton("summer");
    QPushButton *dish_2_category_1_btn = new QPushButton("winter");
    QPushButton *dish_3_category_1_btn = new QPushButton("otm");
    dish_grid_1->addWidget(dish_1_category_1_btn,0,0);
    dish_grid_1->addWidget(dish_2_category_1_btn,0,1);
    dish_grid_1->addWidget(dish_3_category_1_btn,0,2);
    dish_grid_1->addWidget(back1,1,0);

    QPushButton *dish_1_category_2_btn = new QPushButton("meat");
    QPushButton *dish_2_category_2_btn = new QPushButton("fish");
    QPushButton *dish_3_category_2_btn = new QPushButton("chicken");
    dish_grid_2->addWidget(dish_1_category_2_btn,0,0);
    dish_grid_2->addWidget(dish_2_category_2_btn,0,1);
    dish_grid_2->addWidget(dish_3_category_2_btn,0,2);
    dish_grid_2->addWidget(back2,1,0);

    QPushButton *dish_1_category_3_btn = new QPushButton("capuch");
    QPushButton *dish_2_category_3_btn = new QPushButton("americano");
    QPushButton *dish_3_category_3_btn = new QPushButton("latte");
    dish_grid_3->addWidget(dish_1_category_3_btn,0,0);
    dish_grid_3->addWidget(dish_2_category_3_btn,0,1);
    dish_grid_3->addWidget(dish_3_category_3_btn,0,2);
    dish_grid_3->addWidget(back3,1,0);

    QPushButton *dish_1_category_4_btn = new QPushButton("green");
    QPushButton *dish_2_category_4_btn = new QPushButton("black");
    QPushButton *dish_3_category_4_btn = new QPushButton("mocha");
    dish_grid_4->addWidget(dish_1_category_4_btn,0,0);
    dish_grid_4->addWidget(dish_2_category_4_btn,0,1);
    dish_grid_4->addWidget(dish_3_category_4_btn,0,2);
    dish_grid_4->addWidget(back4,1,0);


    QObject::connect(category_1_btn, &QPushButton::clicked, [=]() {
        categoryWidget_stack->setCurrentWidget(dish_category_1_widget); // Переключение на виджет 2 при нажатии кнопки
    });

    QObject::connect(category_2_btn, &QPushButton::clicked, [=]() {
        categoryWidget_stack->setCurrentWidget(dish_category_2_widget); // Переключение на виджет 2 при нажатии кнопки
    });

    QObject::connect(category_3_btn, &QPushButton::clicked, [=]() {
        categoryWidget_stack->setCurrentWidget(dish_category_3_widget); // Переключение на виджет 2 при нажатии кнопки
    });

    QObject::connect(category_4_btn, &QPushButton::clicked, [=]() {
        categoryWidget_stack->setCurrentWidget(dish_category_4_widget); // Переключение на виджет 2 при нажатии кнопки
    });

    QObject::connect(back1, &QPushButton::clicked, [=]() {
        categoryWidget_stack->setCurrentWidget(category_widget); // Переключение на виджет 2 при нажатии кнопки
    });

    QObject::connect(back2, &QPushButton::clicked, [=]() {
        categoryWidget_stack->setCurrentWidget(category_widget); // Переключение на виджет 2 при нажатии кнопки
    });

    QObject::connect(back3, &QPushButton::clicked, [=]() {
        categoryWidget_stack->setCurrentWidget(category_widget); // Переключение на виджет 2 при нажатии кнопки
    });

    QObject::connect(back4, &QPushButton::clicked, [=]() {
        categoryWidget_stack->setCurrentWidget(category_widget); // Переключение на виджет 2 при нажатии кнопки
    });


    setLayout(mainLayout);
}