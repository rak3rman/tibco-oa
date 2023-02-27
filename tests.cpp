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

/* **************************************************
 * zerosToTheFront()
 * *************************************************/

// NOTE: Test cases not written for the edge case where
//       count is beyond amount allocated for array,
//       results in undefined behavior

TEST(zerosToTheFrontTest, emptyArrZeroCount) {
    int *array = nullptr;
    int count = 0;

    zerosToTheFront(array, count);
    ASSERT_EQ(array, nullptr);
}

TEST(zerosToTheFrontTest, emptyArrPosCount) {
  int *array = nullptr;
  int count = 2;

  zerosToTheFront(array, count);
  ASSERT_EQ(array, nullptr);
}

TEST(zerosToTheFrontTest, emptyArrNegCount) {
  int *array = nullptr;
  int count = -1;

  zerosToTheFront(array, count);
  ASSERT_EQ(array, nullptr);
}

TEST(zerosToTheFrontTest, seqArrValidCount) {
  int *array = new int[10];
  for (int i = 0; i < 10; i++) { array[i] = i; }
  int count = 10;

  zerosToTheFront(array, count);
  for (int i = 0; i < 10; i++) { ASSERT_EQ(array[i], i); }

  delete[] array;
}

TEST(zerosToTheFrontTest, seqArrValidCountBig) {
  int *array = new int[10000];
  for (int i = 0; i < 10000; i++) { array[i] = i; }
  int count = 10000;

  zerosToTheFront(array, count);
  for (int i = 0; i < 10000; i++) { ASSERT_EQ(array[i], i); }

  delete[] array;
}

TEST(zerosToTheFrontTest, seqArrUnderCount) {
  int *array = new int[10];
  for (int i = 0; i < 10; i++) { array[i] = i; }
  int count = 8;

  zerosToTheFront(array, count);
  for (int i = 0; i < 10; i++) { ASSERT_EQ(array[i], i); }

  delete[] array;
}

TEST(zerosToTheFrontTest, seqRevArrValidCount) {
  int *array = new int[10];
  for (int i = 0; i < 10; i++) { array[i] = 9 - i; }
  int count = 10;

  zerosToTheFront(array, count);
  for (int i = 0; i < 1; i++) { ASSERT_EQ(array[i], 0); }
  for (int i = 1; i < 10; i++) { ASSERT_NE(array[i], 0); }

  delete[] array;
}

TEST(zerosToTheFrontTest, seqRevArrUnderCount) {
  int *array = new int[10];
  for (int i = 0; i < 10; i++) { array[i] = 9 - i; }
  int count = 9;

  zerosToTheFront(array, count);
  for (int i = 9; i < 10; i++) { ASSERT_EQ(array[i], 0); }
  for (int i = 0; i < 9; i++) { ASSERT_NE(array[i], 0); }

  delete[] array;
}

TEST(zerosToTheFrontTest, balArrValidCount) {
  int *array = new int[20];
  for (int i = 0; i < 20; i++) { array[i] = 9 - i; }
  int count = 20;

  zerosToTheFront(array, count);
  for (int i = 0; i < 1; i++) { ASSERT_EQ(array[i], 0); }
  for (int i = 1; i < 20; i++) { ASSERT_NE(array[i], 0); }

  delete[] array;
}

TEST(zerosToTheFrontTest, randArrValidCount) {
  for (int count = 0; count < 50; count++) {
    int *array = new int[count];
    for (int i = 0; i < count; i++) { array[i] = rand() % 100 - 50; } // Picks random -50 to 50

    int zeros = 0;
    for (int i = 0; i < count; i++) {
      if (array[i] == 0) zeros++;
    }

    zerosToTheFront(array, count);
    for (int i = 0; i < zeros; i++) { ASSERT_EQ(array[i], 0); }
    for (int i = zeros; i < count; i++) { ASSERT_NE(array[i], 0); }

    delete[] array;
  }
}

TEST(zerosToTheFrontTest, randArrRandCount) {
  for (int count = 0; count < 500; count++) {
    int *array = new int[count];
    for (int i = 0; i < count; i++) { array[i] = rand() % 100 - 50; } // Picks random -50 to 50
    int randCount = count - rand() % 5; // Redefine count

    int zeros = 0;
    for (int i = 0; i < randCount; i++) {
      if (array[i] == 0) zeros++;
    }

    zerosToTheFront(array, randCount);
    for (int i = 0; i < zeros; i++) { ASSERT_EQ(array[i], 0); }
    for (int i = zeros; i < randCount; i++) { ASSERT_NE(array[i], 0); }

    delete[] array;
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}