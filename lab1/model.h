#ifndef MODEL_H
#define MODEL_H
#include "edge.h"
#include "node.h"
#include "error_handler.h"
#include <cstdio>

typedef struct
{
     int number_of_nodes;
     int number_of_edges;
     node* nodes;
     edge* edges;
     node center_of_figure;
     bool is_set;
} model;


model init_model();

errors read_center_of_figure(model &figure, FILE *f);

errors copy_figure_and_delete_old(model &target, model &source);

errors load_model_from_file(model &figure, char* file_name);

errors clear_figure(model &figure);

#endif // MODEL_H
