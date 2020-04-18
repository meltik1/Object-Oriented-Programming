#include "graphics.h"

errors init_scene(QGraphicsScene* scene){
    if (!scene)
    {
        return MEMORY_ALLOCATION_ERROR;
    }

    scene->setSceneRect(0, 0, 300, 300);
    return OK;

}

errors set_new_scene(graphics_data &data) {

    QGraphicsScene *scene = new QGraphicsScene();

    errors err = init_scene(scene);

    if (err != OK) {
        return err;
    }

    delete_scene(data);

    data.view->setScene(scene);

    return OK;
}

errors delete_scene(graphics_data &data) {
    QGraphicsScene *scene = data.view->scene();
    delete scene;
    return OK;
}


