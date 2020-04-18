#ifndef EDGE_H
#define EDGE_H
#include "node.h"
#include "error_handler.h"

typedef struct {
    int start;
    int end;
} edge;

errors read_edge(edge& side, FILE* f);


errors read_n_edges(edge* edges, int number_of_sides, FILE *F);

errors set_edge(edge& side, int index_1, int index_2);

errors allocate_n_edges(edge** edges, int number_of_sides);

errors free_edges(edge* edges);

errors init_edge(edge& side);


#endif // EDGE_H
