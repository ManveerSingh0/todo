#ifndef TODO_H
#define TODO_H
// std libraries
#include <iostream> 
#include <vector>


// Qt libraries
#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include <QVBoxLayout>
#include <qboxlayout.h>
#include <QHBoxLayout>
#include <QListWidgetItem>



class Todo : public QMainWindow {

  Q_OBJECT
public:
  Todo(QMainWindow *parent = nullptr);


private slots:
  void add_task();
  void delete_task();
  void save_tasks();
  bool is_duplicate(QString);
private:
  void show_input_area();
  void buttons();

private:
  QLineEdit* task_input;
  QWidget* central_widget;
  QListWidget* task_list;


  //Buttoons To add and remove Tasks
  QPushButton* add_button;
  QPushButton *delete_button;

  std::vector<QString> not_duplicate;



};







#endif //TODO_H 
