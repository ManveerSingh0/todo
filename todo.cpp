#include "todo.h"
#include <QWidget>
#include <QVBoxLayout>
#include <qboxlayout.h>
#include <QHBoxLayout>

Todo::Todo(QMainWindow* parent) : QMainWindow(parent) {
  /*
    This central widget will show all the ui interface for todo.
    i have set it to be the central widget for MainWindow
  */
  this->central_widget = new QWidget(this);
  this->setCentralWidget(this->central_widget);


  //This function modifies and uses QLineEdit to take input from user and later add it to the list
  this->show_input_area();
  this->buttons();
  


  //QVBoxLayout  manages layout for QLineEdit and QListWidgetItem
  QVBoxLayout* v_layout = new QVBoxLayout(this->central_widget);

  QHBoxLayout *h_layout = new QHBoxLayout();
  h_layout->addWidget(this->add_button);
  h_layout->addWidget(this->task_input);
  h_layout->addWidget(this->delete_button);

  v_layout->addLayout(h_layout);


}

void Todo::add_task() {

}
void Todo::delete_task() {

}
void Todo::save_tasks() {}


void Todo::show_input_area() {
  this->task_input = new QLineEdit(this->central_widget);
}


void Todo::buttons() {
  this->add_button = new QPushButton("Add Task");
  QObject::connect(add_button, &QPushButton::clicked, this, &this->add_task);


  this->delete_button = new QPushButton("Delete Task");
  QObject::connect(delete_button, &QPushButton::clicked, this, &this->delete_task);
}
