#include "triangle.h"
triangle::triangle(): _a{0, 0}, _b{0, 0}{}
triangle::triangle(const point& a, const point& b, const point& c) : _a{a}, _b{b}, _c{c} {
    double l, k, p;
    l = sqrt((_a.x - _b.x) * (_a.x - _b.x) + (_a.y - _b.y) * (_a.y - _b.y));
    k = sqrt((_b.x - _c.x) * (_b.x - _c.x) + (_b.y - _c.y) * (_b.y - _c.y));
    p = sqrt((_c.x - _b.x) * (_c.x - _b.x) + (_c.y - _b.y) * (_c.y - _b.y));
    if (l + k <= p || l + p <= k || p + k <= l) {
        throw std::logic_error("Triangle doesn't exist");
    }
}
triangle::triangle(std::istream& is) {
    is >> _a >> _b >> _c;
    double l, k, p;
    l = sqrt((_a.x - _b.x) * (_a.x - _b.x) + (_a.y - _b.y) * (_a.y - _b.y));
    k = sqrt((_b.x - _c.x) * (_b.x - _c.x) + (_b.y - _c.y) * (_b.y - _c.y));
    p = sqrt((_c.x - _b.x) * (_c.x - _b.x) + (_c.y - _b.y) * (_c.y - _b.y));
    if (l + k <= p || l + p <= k || p + k <= l) {
        throw std::logic_error("Triangle doesn't exist");
    }
}
double triangle::square() const {
    return fabs(((_a.x - _c.x) * (_b.y - _c.y) - (_b.x - _c.x) * (_a.y - _c.y)) / 2);
}
point triangle::center() const {
    return point{(_a.x + _b.x + _c.x) / 3, (_a.y + _b.y + _c.y) / 3};
}
std::ostream& triangle::print(std::ostream& os) const {
    os << _a  <<  _b  << _c << std::endl;
    return os;
}
