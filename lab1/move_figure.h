#ifndef MOVE_FIGURE_H
#define MOVE_FIGURE_H

#include "model.h"

typedef struct {
    double dx;
    double dy;
    double dz;
}move_data;

errors set_move_data(move_data &source, double dx, double dy, double dz);

errors move_figure(model &figure, move_data move);
errors move_nodes(model& figure, move_data move);

#endif // MOVE_FIGURE_H
