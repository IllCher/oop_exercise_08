#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE figures

#include "../octagon.h"
#include "../triangle.h"
#include "../quadrate.h"
#include "../processor.h"
#include <sstream>
#include <memory>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(figures);

BOOST_AUTO_TEST_CASE(octagon) {
        {
                point p1 = {0,0}, p2 = {1, 2}, p3 = {4, 5}, p4 = {11,0}, p5 = {0,0}, p6 = {1, 2}, p7 = {4, 5}, p8 = {11,0};
        BOOST_CHECK_THROW(octagon(p1,p2,p3,p4,p5,p6,p7,p8), std::logic_error);
        }
}

BOOST_AUTO_TEST_CASE(triangle) {
        {
                point p1 = {0,0}, p2 = {1, 2}, p3 = {4, 5};
        BOOST_CHECK_THROW(triangle(p1,p2,p3), std::logic_error);
        }
}

BOOST_AUTO_TEST_CASE(quadrate) {
        {
                point p1 = {0,0}, p2 = {1, 1};
        BOOST_CHECK_NO_THROW(quadrate(p1,p2));
        }
}


BOOST_AUTO_TEST_SUITE_END()

