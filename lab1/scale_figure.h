#ifndef SCALE_FIGURE_H
#define SCALE_FIGURE_H
#include "model.h"

typedef struct  {
    double kx;
    double ky;
    double kz;
}scale_data ;

errors set_scale_data(scale_data &source, double kx, double ky, double kz);

errors scale_figure(model& figure, scale_data sca);

errors scale_nodes(model &figure, scale_data sca);

#endif // SCALE_FIGURE_H
