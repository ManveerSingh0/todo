#include "todo.h"
#include <qnamespace.h>


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
  

  this->task_list = new QListWidget();


  //QVBoxLayout  manages layout for QLineEdit and QListWidgetItem
  QVBoxLayout* v_layout = new QVBoxLayout(this->central_widget);

  QHBoxLayout *h_layout = new QHBoxLayout();
  h_layout->addWidget(this->add_button);
  h_layout->addWidget(this->task_input);
  h_layout->addWidget(this->delete_button);

  v_layout->addLayout(h_layout);
  v_layout->addWidget(this->task_list);


}

void Todo::add_task() {
  QString input_text = this->task_input->text();

  if (!input_text.isEmpty()&& not_duplicate.find(input_text) == not_duplicate.end()) {
    QListWidgetItem *item = new QListWidgetItem(input_text);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    task_list->addItem(item);


    not_duplicate.insert(input_text);
  } else {
    std::cout << "Enter Text\n";
  }
}


void Todo::delete_task() {
    // Get all checked items
    QList<QListWidgetItem*> checkedItems;
    
    // Loop through all items in the list
    for(int i = 0; i < task_list->count(); ++i) {
        QListWidgetItem* item = task_list->item(i);
        if(item->checkState() == Qt::Checked) {
            checkedItems.append(item);
        }
    }

    // Delete checked items safely
    for(QListWidgetItem* item : checkedItems) {
        // Remove from duplicate tracker
        not_duplicate.erase(item->text());  // For std::unordered_set
        
        // Get the current row of the item
        int row = task_list->row(item);
        if (row >= 0) {  // Ensure the row is valid
            QListWidgetItem* takenItem = task_list->takeItem(row);
            delete takenItem;  // Safely delete the item
        } else {
            qDebug() << "Item not found in list:" << item->text();
        }
    }

    // Optional: Show message if no checked items
    if(checkedItems.isEmpty()) {
        qDebug() << "No checked items found";
    }
}




void Todo::save_tasks() {}


void Todo::show_input_area() {
  this->task_input = new QLineEdit(this->central_widget);
}


void Todo::buttons() {
  this->add_button = new QPushButton("Add Task");
  QObject::connect(add_button, &QPushButton::clicked, this, &Todo::add_task);


  this->delete_button = new QPushButton("Delete Task");
  QObject::connect(delete_button, &QPushButton::clicked, this, &Todo::delete_task);
}
