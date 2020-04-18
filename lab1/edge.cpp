#include "edge.h"
#include <cstdlib>
#include <cstdio>
#include "error_handler.h"


errors read_edge(edge& side, FILE* f)
{
    errors error = OK;

    if (fscanf(f, "%d %d", &side.start, &side.end) != 2 || side.start < 0 || side.end < 0)
    {
        error =  DATA_READ_ERROR;
    }
    return error;
}


errors read_n_edges(edge* edges, int number_of_sides, FILE *f)
{
    if (!f) {
        return FILE_OPENING_ERROR;
    }

    if (number_of_sides <= 0) {
        return WRONG_NUMBER_OF_EDGES;
    }


    errors err = OK;

    for (int i = 0; i < number_of_sides && err == OK; i++) {
         err = read_edge(edges[i], f);
    }

    return OK;
}

errors allocate_n_edges(edge** edges, int number_of_sides)
{
    if (number_of_sides <= 0) {
        return WRONG_NUMBER_OF_EDGES;
    }

    *edges = new edge[number_of_sides];

    if (!(*edges)) {
        return MEMORY_ALLOCATION_ERROR;
    }

    return OK;
}

errors free_edges(edge *edges) {
    delete edges;
    return OK;
}

errors init_edge(edge& side) {
    side.start = 0;
    side.end = 0;

    return OK;
}
