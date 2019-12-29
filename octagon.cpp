#include "octagon.h"
octagon::octagon(): _a{0, 0}, _b{0, 0}{}
octagon::octagon(std::istream& is) {
    is >> _a >> _b >> _c >> _d >> _e >> _f >> _g >> _h;
}
octagon::octagon(const point& a, const point& b, const point& c, const point& d, const point& e, const point& f, const point& g, const point& h) : _a{a}, _b{b}, _c{c}, _d{d}, _e{e}, _f{f}, _g{g}, _h{h}{}
double octagon::square() const {
    return fabs(((_a.x * _b.y) + (_b.x * _c.y) + (_c.x * _d.y) + (_d.x * _e.y) + (_e.x * _f.y) + (_f.x * _g.y) + (_g.x * _h.y) + (_h.x * _a.y) - (_b.x * _a.y) - (_c.x * _b.y) - (_d.x * _c.y) - (_e.x * _d.y) - (_f.x * _e.y) - (_g.x * _f.y) - (_h.x * _g.y) - (_a.x * _h.y)) / 2);
}
point octagon::center() const {
    return point{(_a.x + _b.x + _c.x + _d.x + _e.x + _f.x + _g.x + _h.x) / 8, (_a.y + _b.y + _c.y + _d.y + _e.y + _f.y + _g.y + _h.y) / 8};
}
std::ostream& octagon::print(std::ostream& os) const {
    os << _a <<  _b << _c <<  _d << _e <<  _f << _g <<  _h << std::endl;
    return os;
}
