#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "model.h"
#include "draw_figure.h"
#include "rotate_figure.h"
#include "scale_figure.h"
#include "move_figure.h"


enum request_type {
    INIT,
    LOAD_MODEL,
    DRAW_MODEL,
    MOVE_MODEL,
    SCALE_MODEL,
    ROTATE_MODEL,
    QUIT
};

struct file_data {
    char* file_name;
};

typedef struct  {
    request_type type;

    struct file_data file;
    graphics_data graph;
    move_data mov;
    scale_data sca;
    rotation_data rot;

} request;


errors request_handle(request req);
errors set_draw_type(request &req, graphics_data data);
errors set_rotate_type(request &req, rotation_data data);
errors set_move_type(request &req,  move_data data);
errors set_scale_type(request &req, scale_data data);
errors set_load_type(request &req, struct file_data data);
errors set_quit_type(request &req);



#endif // TASK_MANAGER_H
