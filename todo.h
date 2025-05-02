#ifndef TODO_H
#define TODO_H



// Qt libraries
#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>


class Todo : public QMainWindow {

  Q_OBJECT
public:
  Todo(QMainWindow *parent = nullptr);


private slots:
  void add_task();
  void delete_task();
  void save_tasks();

private:
  QListWidget* task_list;
  QLineEdit* task_input;
  QPushButton* add_button;
  QPushButton* delete_button;
};







#endif //TODO_H 
