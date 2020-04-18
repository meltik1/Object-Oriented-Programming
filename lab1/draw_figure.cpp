#include "draw_figure.h"

errors draw_line(graphics_data gv, node2d node_1, node2d node_2)
{

    QGraphicsScene *scene = gv.view->scene();

    double x1 = node_1.x;
    double y1 =  scene->height() - node_1.y;

    double x2 = node_2.x;
    double y2 = scene->height() - node_2.y;

    scene->addLine(x1, y1, x2, y2, gv.pen);

    return OK;
}


node2d get_node2d(const node *nodes, int index)
{
    node2d dot;
    dot.x = nodes[index].x;
    dot.y = nodes[index].y;
    return dot;
}



errors draw_edges(graphics_data gr, model proj) {

    for (int i = 0; i < proj.number_of_edges; i++) {

        node2d start = get_node2d(proj.nodes, proj.edges[i].start);
        node2d end = get_node2d(proj.nodes, proj.edges[i].end);

        draw_line(gr, start, end);
    }

    return OK;
}

errors draw_figure(graphics_data graph, model figure ) {
    if (!figure.is_set) {
        return MODEL_IS_NOT_INITIALIZED;
    }

    errors err = set_new_scene(graph);
    if (err != OK) {
        return err;
    }

    draw_edges(graph, figure);

    return OK;
}




