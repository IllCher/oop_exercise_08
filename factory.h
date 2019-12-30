#ifndef OOP_EXERCISE_08_FACTORY_H
#define OOP_EXERCISE_08_FACTORY_H

#include <memory>
#include <iostream>
#include <fstream>
#include "figure.h"
#include <string>

struct factory {
    std::shared_ptr<figure> new_figure(std::istream& is);
};

#endif //OOP_EXERCISE_08_FACTORY_H
