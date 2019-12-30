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

BOOST_AUTO_TEST_CASE(console_processor) {
        std::stringstream buffer;
        std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());
        std::vector<std::shared_ptr<Figure>> v;
        v.push_back(std::make_shared<Pentagon>(point{1,2},point{3,4},point{5,6},point{7,8},point{9,10}));
        v.push_back(std::make_shared<quadrate>(point{0,0}, point{3, 4}, point{8, 4}, point{5,0}));
        v.push_back(std::make_shared<octagon>(point{0,0}, point{0, 4}, point{4, 4}, point{6,0}));
        ConsoleProcessor proc;
        proc.Process(v);
        std::string output = "Pentagon, p1: 1 2, p2: 3 4, p3: 5 6, p4: 7 8, p5: 9 10\n"
        "quadrate, p1: 0 0, p2: 3 4, p3: 8 4, p4: 5 0\n"
        "octagon, p1: 0 0, p2: 4 4, p3: 0 4, p4: 6 0\n";
        BOOST_CHECK_EQUAL(output, buffer.str());
        std::cout.rdbuf(old);
}

BOOST_AUTO_TEST_SUITE_END()

