// my defined libraries
#include "todo.h"



#include <QApplication>


int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  Todo todo;
  todo.show();


  app.exec();
}

