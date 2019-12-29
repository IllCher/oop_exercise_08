#include "quadrate.h"
quadrate::quadrate(): _a{0, 0}, _c{0, 0}{}
quadrate::quadrate(const point& a, const point& c) : _a{a}, _c{c}{}
quadrate::quadrate(std::istream &is) {
    is >> _a >> _c;
};
double quadrate::square() const {
    return ((_c.x - _a.x) * (_c.x - _a.x) + (_c.y - _a.y) * (_c.y - _a.y))/2;
}
point quadrate::center() const {
    return point{(_a.x + _c.x) / 2, (_a.y + _c.y) / 2};
}
std::ostream& quadrate::print(std::ostream& os) const {
    point m = center();
    point b, d;
    b.x = m.x - _c.y + m.y;
    b.y = m.y + _c.x - m.x;
    d.x = m.x - _a.y + m.y;
    d.y = m.y + _a.x - m.x;
    os << _a  << b << _c << d << std::endl;
    return os;
}

