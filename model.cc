#include "model.h"

Model::Model() {
    display = std::make_unique<Display>();
}

Display * Model::getDisplay() {
    return display.get();
}

