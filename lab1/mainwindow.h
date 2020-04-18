#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "task_manager.h"
#include "defines_and_globals.h"
#include <QMouseEvent>
#include <QPen>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
   void keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;
    QGraphicsScene* mine;
};

#endif // MAINWINDOW_H
