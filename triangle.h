
#ifndef OOP_EXERCISE_03_TRIANGLE_H
#define OOP_EXERCISE_03_TRIANGLE_H

#include "figure.h"

class triangle : public figure {
public:
    triangle();
    triangle(const point& a, const point& b, const point& c);
    triangle(std::istream& is) ;
    double square() const override;
    point center() const override;
    std::ostream& print(std::ostream& os) const override;

private:
    point _a;
    point _b;
    point _c;
};


#endif //OOP_EXERCISE_03_TRIANGLE_H
