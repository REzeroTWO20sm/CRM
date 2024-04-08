cmake_minimum_required(VERSION 3.20)
project(CRM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

set(REGWIDGET
reg_widget/reg_widget.hpp reg_widget/reg_widget.cpp

)
set(DIOLOG_ADD_GUEST
diolog_add_guest/diolog_add_guest.hpp diolog_add_guest/diolog_add_guest.cpp

)
set(STARTWIDGET
start_widget/start_widget.hpp start_widget/start_widget.cpp

)

add_executable(CRM ${REGWIDGET} ${DIOLOG_ADD_GUEST} ${STARTWIDGET} main.cpp)

find_package(Qt6 COMPONENTS Widgets Gui Core)

target_link_libraries(CRM PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)