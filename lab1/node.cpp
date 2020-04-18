#include "node.h"

errors read_node(node& dot, FILE* f) {
    init_node(dot);

    if (fscanf(f, "%lf %lf %lf", &dot.x, &dot.y, &dot.z) != 3) {
        return DATA_READ_ERROR;
    }
    return OK;
}

errors read_n_nodes(node* nodes, int number_of_nodes, FILE* f) {
    if (!f) {
        return FILE_OPENING_ERROR;
    }

    if (number_of_nodes <= 0) {
        return WRONG_NUMBER_OF_NODES;
    }
    errors err = OK;

    for (int i = 0; i < number_of_nodes && err == OK; i++)
    {
         err = read_node(nodes[i], f);

    }
    return err;

}

errors allocate_n_nodes(node** nodes, int number_of_nodes)
{
    if (number_of_nodes <= 0) {
        return WRONG_NUMBER_OF_NODES;
    }

    *nodes = new node[number_of_nodes];

    if (!(*nodes)) {
        return MEMORY_ALLOCATION_ERROR;
    }

    return OK;
}

errors init_node(node& dot) {
    dot.x = 0;
    dot.y = 0;
    dot.z = 0;
    return OK;
}



errors scale_node(node& dot, double dx, double dy, double dz, const node center_of_scale){
    double center_x = dot.x;
    double center_y = dot.y;
    double center_z = dot.z;


    dot.x =  (center_x*dx + (1-dx)*center_of_scale.x);
    dot.y = (center_y*dy + (1-dy)*center_of_scale.y);
    dot.z = (center_z*dz + (1-dz)*center_of_scale.z);

    return OK;
}

errors rotate_node_dx(node &dot,   double angle, const node center_of_rotation) {
    double yc = center_of_rotation.y;
    double zc = center_of_rotation.z;

    double rads = angle * pi_num/180;


    double y = dot.y;
    double z = dot.z;

    dot.y = yc + (y - yc)*cos(rads) - (z - zc)*sin(rads); // заменить лучше
    dot.z = zc + (z - zc)*cos(rads) + (y - yc)*sin(rads);

    return OK;
}

errors rotate_node_dy(node &dot,  double angle, const node center_of_rotation) {
    double xc = center_of_rotation.x;
    double zc = center_of_rotation.z;

    double rads = angle * pi_num/180;

    double x = dot.x;
    double z = dot.z;

     dot.x = xc + (x-xc) * cos(rads) - (z-zc) * sin(rads);
     dot.z = zc + (z-zc) * cos(rads) + (x-xc) * sin(rads);

     return OK;
}

errors rotate_node_dz(node& dot,  double angle, const node center_of_rotation) {
    double xc = center_of_rotation.x;
    double yc = center_of_rotation.y;

    double rads = angle * pi_num/180;

    double x = dot.x;
    double y = dot.y;

    dot.x = xc +  (x -xc)*cos(rads) - (y- yc)*sin(rads);
    dot.y = yc +  (y - yc)*cos(rads) + (x-xc)*sin(rads);

    return OK;

}

errors free_nodes(node *nodes) {
    delete nodes;
    return OK;
}

errors move_node(node& dot, double dx, double dy, double dz) {
    dot.x += dx;
    dot.y += dy;
    dot.z +=dz;

    return OK;
}
