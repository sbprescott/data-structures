#include <iostream>
#include <stdexcept>
#include <string>
#include "vector.h"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE( "Vector default constructor")
{
    Vector v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
}

TEST_CASE("Vector constructor with size")
{
    Vector v(2);
    v[0] = 1;
    v[1] = 2;
    REQUIRE((v[0] == 1 && v[1] == 2));
    REQUIRE(v.size() == 2);
    REQUIRE(v.capacity() == 2);
}

TEST_CASE("Negative size")
{
    try
    {
        REQUIRE_THROWS_AS(Vector(-1), std::length_error);
    }
    catch (std::length_error)
    {
        std::cout << "length_error\n";
    }
    catch (std::bad_alloc)
    {
        std::cout << "bad_alloc\n";
    }
      
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

TEST_CASE("Vector copy assignment")
{
    Vector v1({1,2});
    Vector v2 = v1;
    REQUIRE(v1 == v2);
}

TEST_CASE("Vector move assignment/constructor")
{
    Vector v1({1,2});
    Vector v2({3,4});
    Vector v3 = v1; // v3 copied from v2
    Vector v4 = v2; // v4 copied from v3
    Vector v5;
    v5 = std::move(v1); // call vector's move assignment explicitly
    Vector v6(std::move(v2)); // call vector's move constructor explicitly
    REQUIRE(v3 == v5);
    REQUIRE(v4 == v6);
    REQUIRE(v1.size() == 0); // after move, v1 & v2 will be empty
    REQUIRE(v2.size() == 0);
}

TEST_CASE("Resize")
{
    Vector v1;
    Vector v2({1,2});
    Vector v3({1,2,3,4});

    v1.resize(1);
    v2.resize(4);
    v3.resize(3);

    REQUIRE(v1.size() == 0);
    REQUIRE(v1.capacity() == 1);
    REQUIRE(v2.size() == 2);
    REQUIRE(v2.capacity() == 4);
    REQUIRE(v3.size() == 3);
    REQUIRE(v3.capacity() == 3);
}

TEST_CASE("resize with negative size") {
    Vector v({1});
    REQUIRE_THROWS_AS(v.resize(-1), std::length_error);
}

TEST_CASE("push_back()")
{
    Vector v1;
    Vector v2({1});

    v1.push_back(1);
    REQUIRE(v1.size() == 1);
    REQUIRE(v1.capacity() == 2);
    REQUIRE(v1 == Vector({1}));

    
    v2.push_back(2);
    REQUIRE(v2.size() == 2);
    REQUIRE(v2.capacity() == 2);
    REQUIRE(v2[1] == Vector({1,2}));
}

TEST_CASE("at()") {
    Vector v({1});
    REQUIRE(v.at(0) == 1);
}

TEST_CASE("front()") {
    Vector v({1,2});
    REQUIRE(v.front() == 1);
}

TEST_CASE("front() on empty vector") {
    Vector v;
    REQUIRE_THROWS_AS(v.front(), std::out_of_range);
}

TEST_CASE("back()") {
    Vector v({1,2});
    REQUIRE(v.back() == 2);
}

TEST_CASE("back() on empty vector") {
    Vector v;
    REQUIRE_THROWS_AS(v.back(), std::out_of_range);
}

TEST_CASE("at() out of range")
{
    Vector v({1});
    REQUIRE_THROWS_AS(v.at(1), std::out_of_range);
}