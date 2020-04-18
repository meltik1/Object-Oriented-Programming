#include "scale_figure.h"

errors set_scale_data(scale_data &source, double kx, double ky, double kz) {
    source.kx = kx;
    source.ky = ky;
    source.kz = kz;

    return OK;
}

errors scale_figure(model& figure, scale_data sca) {

    if (!figure.is_set) {
        return MODEL_IS_NOT_INITIALIZED;
    }

    scale_nodes(figure, sca);

    return OK;
}

errors scale_nodes(model &figure, scale_data sca) {
    for (int i = 0; i < figure.number_of_nodes; i++) {
         scale_node(figure.nodes[i], sca.kx,  sca.ky, sca.kz, figure.center_of_figure);
    }

    return OK;
}
