#include "model.h"

model init_model() {
    model figure;

    figure.number_of_edges = 0;
    figure.edges = NULL;

    figure.number_of_nodes = 0;
    figure.nodes = NULL;

    figure.is_set = false;
    return figure;
}

errors read_number_of_nodes(model &figure, FILE *f)
{
    if (!f) {
        return FILE_OPENING_ERROR;
    }

    if (fscanf(f, "%d", &figure.number_of_nodes) != 1 || figure.number_of_nodes <= 0)
    {
        return WRONG_NUMBER_OF_NODES;
    }
    return OK;
}

errors read_number_of_edges(model &figure, FILE *f)
{
    if (!f) {
        return FILE_OPENING_ERROR;
    }

    if (fscanf(f, "%d", &figure.number_of_edges) != 1 || figure.number_of_edges <= 0)
    {
        return WRONG_NUMBER_OF_NODES;
    }
    return OK;
}

errors read_center_of_figure(model &figure, FILE *f) {
     errors err = read_node(figure.center_of_figure, f);
     return err;
}


errors copy_figure_and_delete_old(model &target, model &source)
{
    clear_figure(target);
    target = source;
    return OK;
}

errors read_nodes_from_file(model &figure, FILE* f ){
    errors err = OK;
    err = read_number_of_nodes(figure, f);
    if (err == OK) {
        err = allocate_n_nodes(&figure.nodes, figure.number_of_nodes);
        if (err == OK) {
            err = read_n_nodes(figure.nodes, figure.number_of_nodes, f);
        }
        else {
            free_nodes(figure.nodes);
        }
   }
   return err;

}

errors read_edges_from_file(model &figure,FILE* f ){
    errors err = OK;
    err = read_number_of_edges(figure, f);
    if (err == OK) {
        err = allocate_n_edges(&figure.edges, figure.number_of_edges);
        if (err == OK) {
            err = read_n_edges(figure.edges, figure.number_of_edges, f);
        }
        else {
            free_edges(figure.edges);
        }
   }
   return err;

}

errors clear_figure(model &figure)
{
    free_nodes(figure.nodes);
    free_edges(figure.edges);

    return OK;
}


errors load_model_from_file(model &figure,  char *file_name) {
    FILE *f = fopen(file_name, "r"); // проконтролллировать загрузку фигуры
    if (!f) {
        return FILE_OPENING_ERROR;
    }

    model tmp = init_model();

    errors err = read_nodes_from_file(tmp, f); // лишние данные
    if (err == OK) {
        err = read_edges_from_file(tmp, f);
        if (err != OK) {
            free_nodes(tmp.edges);
        }
        else {
            err = read_center_of_figure(tmp, f);
            if (err != OK) {
                clear_figure(tmp);
            }
        }
    }

    fclose(f);
    if (err == OK)
    {
        copy_figure_and_delete_old(figure, tmp); // перечисление , разбить на две
    }

    if (err == OK) {
        figure.is_set = true;
    }

    return err;
}




