#include "error_handler.h"


int error_handler(errors error_type) {
    switch (error_type) {

    case (DATA_READ_ERROR):
        QMessageBox::critical(NULL, "Error", "Ivalid data format in file");
        break;
    case (FILE_OPENING_ERROR):
        QMessageBox::critical(NULL, "Error", "File opening error");
        break;
    case (MEMORY_ALLOCATION_ERROR):
        QMessageBox::critical(NULL, "Error", "Memory allocation error");
        break;
    case (MODEL_IS_NOT_INITIALIZED):
        QMessageBox::critical(NULL, "Error", "Model is not initialized");
        break;
    case (WRONG_NUMBER_OF_EDGES):
        QMessageBox::critical(NULL, "Error", "Wrong number of edges");
        break;
    case (WRONG_NUMBER_OF_NODES):
        QMessageBox::critical(NULL, "Error", "Wrong number of nodes");
        break;
    case (NO_SUCH_COMMAND):
        QMessageBox::critical(NULL, "Error", "No such command detected");
        break;
    case (NO_SCENE_DETECTED):
        QMessageBox::critical(NULL, "Error", "No scene detected");
        break;
    }

    return 0;
}
