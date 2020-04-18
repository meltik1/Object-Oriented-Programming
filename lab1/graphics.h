#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QGraphicsView>
#include "error_handler.h"

typedef struct
{
    QGraphicsView* view;
    QGraphicsScene* current_scene;
    QPen pen;

} graphics_data;

errors init_scene(QGraphicsScene* scene);

errors set_new_scene(graphics_data &data);

errors delete_scene(graphics_data &data);

#endif // GRAPHICS_H
