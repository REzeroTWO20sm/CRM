#include "reg_widget/reg_widget.hpp"
#include "diolog_add_guest/diolog_add_guest.hpp"
#include "start_widget/start_widget.hpp"
#include <QApplication>

// if ERROR: symbol lookup error: /snap/core20/current/lib/x86_64-linux-gnu/libpthread.so.0: undefined symbol: __libc_pthread_init, version GLIBC_PRIVATE 
// write to console unset GTK_PATH

int main(int argc,char **argv){
    QApplication app(argc,argv);

    //QMainWindow *window = new QMainWindow;

    //reg_Widget window;
    //window.resize(1200,900);
    //window.setWindowTitle("CRM");

    // diologAddGuests_Widget window;
    // window.resize(600,500);
    // window.setWindowTitle("DIOLOG_ADD_GUEST");

    start_Widget window;
    window.resize(600,500);
    window.setWindowTitle("start_window");


    window.show();

    return app.exec();
}