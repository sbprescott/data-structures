#include <iostream>
#include <string>
#include "vector.h"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE( "Vector default constructor")
{
    Vector v;
    REQUIRE(v.size() == 0);
}

TEST_CASE("Vector constructor with size")
{
    Vector v(2);
    v[0] = 1;
    v[1] = 2;
    REQUIRE((v[0] == 1 && v[1] == 2));
    REQUIRE(v.size() == 2);
}

TEST_CASE("Vector initializer list constructor")
{
    Vector v({1,2});
    REQUIRE((v[0] == 1 && v[1] == 2));
    REQUIRE(v.size() == 2);   
}

TEST_CASE("Vector copy constructor")
{
    Vector v1;
    Vector v2({1,2});
    Vector v3(v2);
    REQUIRE(v1 != v2);
    REQUIRE(v2 == v3);
}