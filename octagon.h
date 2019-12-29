#ifndef OOP_EXERCISE_03_OCTAGON_H
#define OOP_EXERCISE_03_OCTAGON_H
#include "figure.h"
class octagon : public figure {
public:
    octagon();
    octagon(const point& a, const point& b, const point& c, const point& d, const point& e, const point& f, const point& g, const point& h);
    octagon(std::istream& is);
    double square() const override;
    point center() const override;
    std::ostream& print(std::ostream&) const override;
private:
    point _a;
    point _b;
    point _c;
    point _d;
    point _e;
    point _f;
    point _g;
    point _h;
};
#endif //OOP_EXERCISE_03_OCTAGON_H
