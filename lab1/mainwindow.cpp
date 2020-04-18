#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include <string.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mine = new QGraphicsScene(0, 0, 1280, 960);
    ui->graphicsView->setScene(mine);

    char *file_name = "data.txt";

    file_data date;
    date.file_name= file_name;

    request req;

    set_load_type(req, date);

    errors err = request_handle(req);

    if (err != OK) {
        error_handler(err);
    }

    graphics_data gr;
    gr.view = ui->graphicsView;
    gr.current_scene = mine;
    gr.pen = QPen(Qt::red);

    set_draw_type(req, gr);
    err = request_handle(req);
      qDebug() << "Hello";


}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    errors err = OK;

    request req;

    const double dx_up = -50;
    const double dx_down = 50;
    const double dx_left = -50;
    const double dx_right = 50;
    const double dx_zero = 0;

    const double zoom_in = 2;
    const double zoom_out = 0.5;

    double clokwise = 20;
    double against_clockwise = -20;

    rotation_data date_rot;
    move_data date_mv;
    scale_data date_sc;

    switch (event->key())
    {
    case Qt::Key_W:

        set_rotate_data(date_rot, against_clockwise, DX);
        set_rotate_type(req, date_rot);
        err = request_handle(req);
        break;
    case Qt::Key_S:
        set_rotate_data(date_rot, clokwise, DX);
        set_rotate_type(req, date_rot);
        err = request_handle(req);
        break;
    case Qt::Key_A:
        set_rotate_data(date_rot, against_clockwise, DY);
        set_rotate_type(req, date_rot);
        err = request_handle(req);
        break;
    case Qt::Key_D:
        set_rotate_data(date_rot, clokwise, DY);
        set_rotate_type(req, date_rot);
        err = request_handle(req);
        break;
    case Qt::Key_PageUp:
        set_move_data(date_mv, dx_zero, dx_up, dx_zero);
        set_move_type(req, date_mv);
        err = request_handle(req);
        break;
    case Qt::Key_PageDown:
        set_move_data(date_mv, dx_zero, dx_down, dx_zero);
        set_move_type(req, date_mv);
        err = request_handle(req);
        break;
    case Qt::Key_Home:
        set_move_data(date_mv, dx_left, dx_zero, dx_zero);
        set_move_type(req, date_mv);
        err = request_handle(req);
        break;
    case Qt::Key_End:
        set_move_data(date_mv, dx_right, dx_zero, dx_zero);
        set_move_type(req, date_mv);
        err = request_handle(req);
        break;
    case Qt::Key_P:
        set_scale_data(date_sc, zoom_in, zoom_in, zoom_in);
        set_scale_type(req, date_sc);
        err = request_handle(req);
        break;
    case Qt::Key_O:
        set_scale_data(date_sc, zoom_out, zoom_out, zoom_out);
        set_scale_type(req, date_sc);
        err = request_handle(req);
        break;
    case Qt::Key_Escape:
        req.type = QUIT;
        err = request_handle(req);
        qApp->quit();
        break;
    default:
        break;
    }
    if (err != OK) {
        error_handler(err);
    }
    graphics_data gr;
    gr.view = ui->graphicsView;
    gr.pen = QPen(Qt::red);

    set_draw_type(req, gr);
    request_handle(req);
}


MainWindow::~MainWindow()
{
    delete ui;
}


