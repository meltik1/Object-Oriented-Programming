#include "rotate_figure.h"


errors set_rotate_data(rotation_data& source, double angle, type_of_rotation type) {
    source.angle = angle;
    source.type = type;

    return OK;
}


errors rotate_figure(model& figure, rotation_data rot) {

    if (!figure.is_set) {
        return MODEL_IS_NOT_INITIALIZED;
    }

    switch (rot.type) {
    case DX:
        rotate_nodes_dx(figure, rot);
        break;
    case DY:
        rotate_nodes_dy(figure, rot);
        break;
    default:
        return INVALID_ROTAION_TYPE;
        break;
    }

    return OK;
}

errors rotate_nodes_dx(model& figure, rotation_data rot) {
    for (int i = 0; i < figure.number_of_nodes; i++) {
        rotate_node_dx(figure.nodes[i], rot.angle, figure.center_of_figure);
    }

    return OK;
}

errors rotate_nodes_dy(model& figure, rotation_data rot) {
    for (int i = 0; i < figure.number_of_nodes; i++) {
         rotate_node_dy(figure.nodes[i],  rot.angle, figure.center_of_figure);
    }

    return OK;
}
errors rotate_nodes_dz(model& figure, rotation_data rot) {
    for (int i = 0; i < figure.number_of_nodes; i++) {
         rotate_node_dz(figure.nodes[i],  rot.angle, figure.center_of_figure);
    }

    return OK;
}
