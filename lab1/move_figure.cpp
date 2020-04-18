#include "move_figure.h"

errors set_move_data(move_data &source, double dx, double dy, double dz) {

    source.dx = dx;
    source.dy = dy;
    source.dz = dz;

    return OK;
}

errors move_figure(model &figure, move_data move)
{
    if (!figure.is_set) {
        return MODEL_IS_NOT_INITIALIZED;
    }

    move_nodes(figure, move);
    return OK;
}

errors move_nodes(model& figure, move_data move)
{

    for (int i = 0; i < figure.number_of_nodes; i++) {
        move_node(figure.nodes[i], move.dx, move.dy, move.dz);
    }

    return OK;
}
