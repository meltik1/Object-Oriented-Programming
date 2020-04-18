#ifndef ROTATE_FIGURE_H
#define ROTATE_FIGURE_H



#include "model.h"
#include <math.h>

enum type_of_rotation {
    DX,
    DY,
    DZ
};

typedef struct {
    double angle;
    type_of_rotation type;
} rotation_data;



errors set_rotate_data(rotation_data& source, double angle, type_of_rotation type);

errors rotate_figure(model& figure, rotation_data rot);

errors rotate_nodes_dx(model& figure, rotation_data rot);
errors rotate_nodes_dy(model& figure, rotation_data rot);
errors rotate_nodes_dz(model& figure, rotation_data rot);

#endif // ROTATE_FIGURE_H
