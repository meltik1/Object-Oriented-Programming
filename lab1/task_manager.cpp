#include "task_manager.h"

errors request_handle(request req) { // оберточный тип, своя структура + данные с командой
    static model figure = init_model();
    errors err = OK;
    switch (req.type) {
    case LOAD_MODEL:
         err = load_model_from_file(figure, req.file.file_name); // исправить глобалбные возвращемое в начало списка параметров
         break;
    case DRAW_MODEL:
        draw_figure(req.graph, figure);
        break;
    case MOVE_MODEL:
        err = move_figure(figure, req.mov);
        break;
    case SCALE_MODEL:
        err = scale_figure(figure, req.sca);
        break;
    case ROTATE_MODEL:
        err = rotate_figure(figure, req.rot);
        break;
    case QUIT:
        clear_figure(figure);
        break;
    default:
        err = NO_SUCH_COMMAND;
        break;
    }
    return err;
}

errors set_draw_type(request &req,  graphics_data data) {
    req.type = DRAW_MODEL;
    req.graph = data;
    return OK;
}
errors set_rotate_type(request &req,  rotation_data data) {
    req.type = ROTATE_MODEL;
    req.rot = data;
    return OK;
}
errors set_move_type(request &req,  move_data data) {
    req.type = MOVE_MODEL;
    req.mov = data;
    return OK;
}
errors set_scale_type(request &req, scale_data data) {
    req.type = SCALE_MODEL;
    req.sca = data;
    return OK;
}
errors set_load_type(request &req, struct file_data data) {
    req.type = LOAD_MODEL;
    req.file = data;
    return OK;
}
errors set_quit_type(request &req) {
    req.type = QUIT;
    return OK;
}
