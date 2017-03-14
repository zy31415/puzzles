//
// Created by zy on 3/13/17.
//


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "stupid/1=2", "Prove that one equals 2" ){
    int one = 1;
    REQUIRE( one == 2 );
}
