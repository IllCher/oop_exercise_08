#include "factory.h"
#include "octagon.h"
#include "quadrate.h"
#include "triangle.h"

std::shared_ptr<figure> factory::new_figure(std::istream &is) {
    std::string name;
    is >> name;
    if ( name == "octagon" ) {
        return std::shared_ptr<figure> ( new octagon(is));
    } else if ( name == "quadrate") {
        return std::shared_ptr<figure> ( new quadrate(is));
    } else if ( name == "triangle") {
        return std::shared_ptr<figure> ( new triangle(is));
    } else {
        throw std::logic_error("no such a figure\n");
    }
}


