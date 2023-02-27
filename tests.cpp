/*
 * Test Suite - GTest
 *
 * Radison Akerman, February 2023
 * TIBCO Coding Assessment
 */

#include "gtest/gtest.h"
#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <thread>

#include "./src/zerosFront.cpp"
#include "./src/byteOrdering.cpp"
#include "./src/epochParse.cpp"

using namespace std;

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}