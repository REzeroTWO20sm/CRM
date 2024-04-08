#include "../diolog_add_guest/diolog_add_guest.hpp"

diologAddGuests_Widget::diologAddGuests_Widget(QWidget *parent) : QWidget(parent){

    QVBoxLayout *mainLayout = new QVBoxLayout;

    QGroupBox *groupBox_labels_and_edits_1 = new QGroupBox;
    QGroupBox *groupBox_labels_and_edits_2 = new QGroupBox;
    QGroupBox *groupBox_labels_and_edits_3 = new QGroupBox;
    QGroupBox *groupBox_labels_and_edits_4 = new QGroupBox;

    QHBoxLayout *guest_card_layout = new QHBoxLayout;
    QHBoxLayout *id_card_layout = new QHBoxLayout;
    QHBoxLayout *table_number_layout = new QHBoxLayout;
    QHBoxLayout *count_people_layout = new QHBoxLayout;

    QLabel *guest_add_label = new QLabel("ADD GUEST");

    QLabel *guest_card_label = new QLabel("CAFE_CART");
    QComboBox *yes_no_comboBox = new QComboBox;

    QLabel *id_card_label = new QLabel("ID_CART");
    QLineEdit *id_card_lineEdit = new QLineEdit;

    QLabel *table_number_label = new QLabel("TABLE_NUM");
    QLineEdit *table_number_lineEdit = new QLineEdit;

    QLabel *count_people_label = new QLabel("COUNT_PEOPLE");
    QLineEdit *count_people_lineEdit = new QLineEdit;

    QPushButton *add_guest_btn = new QPushButton("ADD");

    guest_card_layout->addWidget(guest_card_label);
    yes_no_comboBox->addItem("no");
    yes_no_comboBox->addItem("yes");
    guest_card_layout->addWidget(yes_no_comboBox);

    id_card_layout->addWidget(id_card_label);
    id_card_layout->addWidget(id_card_lineEdit);

    table_number_layout->addWidget(table_number_label);
    table_number_layout->addWidget(table_number_lineEdit);

    count_people_layout->addWidget(count_people_label);
    count_people_layout->addWidget(count_people_lineEdit);

    QObject::connect(add_guest_btn, &QPushButton::clicked, [=] {
        QString buttonText = id_card_lineEdit->text();
        emit buttonAddClicked(buttonText); 
        close();
    });

    groupBox_labels_and_edits_1->setLayout(guest_card_layout);
    groupBox_labels_and_edits_2->setLayout(id_card_layout);
    groupBox_labels_and_edits_3->setLayout(table_number_layout);
    groupBox_labels_and_edits_4->setLayout(count_people_layout);

    mainLayout->addWidget(guest_add_label);
    mainLayout->addWidget(groupBox_labels_and_edits_1);
    mainLayout->addWidget(groupBox_labels_and_edits_2);
    mainLayout->addWidget(groupBox_labels_and_edits_3);
    mainLayout->addWidget(groupBox_labels_and_edits_4);
    mainLayout->addWidget(add_guest_btn);

    setLayout(mainLayout);
}