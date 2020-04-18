#ifndef DRAW_FIGURE_H
#define DRAW_FIGURE_H

#include "model.h"
#include "graphics.h"
#include <QGraphicsScene>
#include <QGraphicsView>


typedef struct
{
    double x;
    double y;
} node2d;



errors draw_line(graphics_data gv, node2d node_1, node2d node_2);


node2d get_node2d(const node *nodes, int index);



errors draw_edges(graphics_data gr, model proj);

errors draw_figure(graphics_data graph, model figure );

errors init_scene(QGraphicsScene* scene);

errors set_new_scene(graphics_data& data);

errors delete_scene(graphics_data& data);


#endif // DRAW_FIGURE_H
