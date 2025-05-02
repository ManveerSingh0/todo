#include "todo.h"
#include <QListWidgetItem>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <qboxlayout.h>
#include <qlistwidget.h>
#include <qnamespace.h>


Todo::Todo(QMainWindow* parent) : QMainWindow(parent) {
  this->resize(400, 400);
  this->setWindowTitle("To-Do");

  QWidget *central_widget = new QWidget(this);
  QVBoxLayout *layout = new QVBoxLayout(central_widget);


  QListWidget* list_widget = new QListWidget(central_widget);
  layout->addWidget(list_widget);

  QListWidgetItem *task_item = new QListWidgetItem("Buy Groceries");
  task_item->setFlags(task_item->flags() | Qt::ItemIsUserCheckable);
  task_item->setCheckState(Qt::Unchecked);
  list_widget->addItem(task_item);


  this->setCentralWidget(central_widget);
}
