#include <iostream>
#include "point.h"
#include <cmath>
#ifndef OOP_EXERCISE_08_FIGURE_H
#define OOP_EXERCISE_08_FIGURE_H
struct figure {
    virtual point center() const = 0;
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual double square() const = 0;
    virtual ~figure() {}
};
#endif