#ifndef NODE_H
#define NODE_H
#include <string>
#include "error_handler.h"
#include <math.h>
#include "defines_and_globals.h"

typedef struct
{
    double x;
    double y;
    double z;

} node;

errors read_node(node& dot, FILE* f);
errors init_node(node& dot);
errors allocate_n_nodes(node** nodes, int number_of_nodes);
errors free_nodes(node* nodes);
errors read_n_nodes(node* nodes, int number_of_nodes, FILE* f);

errors rotate_node_dx(node &dot,  double angle, const node center_of_rotation);
errors rotate_node_dy(node &dot, double angle, const node center_of_rotation);
errors rotate_node_dz(node& dot,  double angle, const node center_of_rotation);

errors scale_node(node& dot, double kx, double ky, double kz, const node center_of_scale);
errors move_node(node& dot, double dx, double dy, double dz);

#endif // NODE_H
