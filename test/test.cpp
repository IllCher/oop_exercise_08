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
        BOOST_CHECK_THROW({0,0},{1, 2},{4, 5},{11,0},{0,0},{1, 2},{4, 5},{11,0}), std::logic_error);
        }
}

BOOST_AUTO_TEST_CASE(triangle) {
        {
        BOOST_CHECK_THROW(triangle({0,0},{1, 2},{4, 5}), std::logic_error);
        }
}

BOOST_AUTO_TEST_CASE(quadrate) {
        {
        BOOST_CHECK_NO_THROW(quadrate({0,0},{1, 1}));
        }
}


BOOST_AUTO_TEST_SUITE_END()

