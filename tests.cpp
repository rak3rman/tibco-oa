/*
 * Test Suite - GTest
 *
 * Radison Akerman, February 2023
 * TIBCO Coding Assessment
 */

#include "gtest/gtest.h"
#include <arpa/inet.h>
#include <bits/stdc++.h>

#include "./src/byteOrdering.cpp"
#include "./src/epochParse.cpp"
#include "./src/zerosFront.cpp"

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
  for (int i = 0; i < 10; i++) {
    array[i] = i;
  }
  int count = 10;

  zerosToTheFront(array, count);
  for (int i = 0; i < 10; i++) {
    ASSERT_EQ(array[i], i);
  }

  delete[] array;
}

TEST(zerosToTheFrontTest, seqArrValidCountBig) {
  int *array = new int[10000];
  for (int i = 0; i < 10000; i++) {
    array[i] = i;
  }
  int count = 10000;

  zerosToTheFront(array, count);
  for (int i = 0; i < 10000; i++) {
    ASSERT_EQ(array[i], i);
  }

  delete[] array;
}

TEST(zerosToTheFrontTest, seqArrUnderCount) {
  int *array = new int[10];
  for (int i = 0; i < 10; i++) {
    array[i] = i;
  }
  int count = 8;

  zerosToTheFront(array, count);
  for (int i = 0; i < 10; i++) {
    ASSERT_EQ(array[i], i);
  }

  delete[] array;
}

TEST(zerosToTheFrontTest, seqRevArrValidCount) {
  int *array = new int[10];
  for (int i = 0; i < 10; i++) {
    array[i] = 9 - i;
  }
  int count = 10;

  zerosToTheFront(array, count);
  for (int i = 0; i < 1; i++) {
    ASSERT_EQ(array[i], 0);
  }
  for (int i = 1; i < 10; i++) {
    ASSERT_NE(array[i], 0);
  }

  delete[] array;
}

TEST(zerosToTheFrontTest, seqRevArrUnderCount) {
  int *array = new int[10];
  for (int i = 0; i < 10; i++) {
    array[i] = 9 - i;
  }
  int count = 9;

  zerosToTheFront(array, count);
  for (int i = 9; i < 10; i++) {
    ASSERT_EQ(array[i], 0);
  }
  for (int i = 0; i < 9; i++) {
    ASSERT_NE(array[i], 0);
  }

  delete[] array;
}

TEST(zerosToTheFrontTest, balArrValidCount) {
  int *array = new int[20];
  for (int i = 0; i < 20; i++) {
    array[i] = 9 - i;
  }
  int count = 20;

  zerosToTheFront(array, count);
  for (int i = 0; i < 1; i++) {
    ASSERT_EQ(array[i], 0);
  }
  for (int i = 1; i < 20; i++) {
    ASSERT_NE(array[i], 0);
  }

  delete[] array;
}

TEST(zerosToTheFrontTest, randArrValidCount) {
  for (int count = 0; count < 50; count++) {
    int *array = new int[count];
    for (int i = 0; i < count; i++) {
      array[i] = rand() % 100 - 50;
    } // Picks random -50 to 50

    int zeros = 0;
    for (int i = 0; i < count; i++) {
      if (array[i] == 0)
        zeros++;
    }

    zerosToTheFront(array, count);
    for (int i = 0; i < zeros; i++) {
      ASSERT_EQ(array[i], 0);
    }
    for (int i = zeros; i < count; i++) {
      ASSERT_NE(array[i], 0);
    }

    delete[] array;
  }
}

TEST(zerosToTheFrontTest, randArrRandCount) {
  for (int count = 0; count < 500; count++) {
    int *array = new int[count];
    for (int i = 0; i < count; i++) {
      array[i] = rand() % 100 - 50;
    }                                   // Picks random -50 to 50
    int randCount = count - rand() % 5; // Redefine count

    int zeros = 0;
    for (int i = 0; i < randCount; i++) {
      if (array[i] == 0)
        zeros++;
    }

    zerosToTheFront(array, randCount);
    for (int i = 0; i < zeros; i++) {
      ASSERT_EQ(array[i], 0);
    }
    for (int i = zeros; i < randCount; i++) {
      ASSERT_NE(array[i], 0);
    }

    delete[] array;
  }
}

/* **************************************************
 * my_ntohs()
 * *************************************************/

TEST(myNtohsShortTest, binarySimple) {
  unsigned short in = 0b0000000000000000;
  ASSERT_EQ(my_ntohs(in), 0b0000000000000000);

  in = 0b0011001100110011;
  ASSERT_EQ(my_ntohs(in), 0b0011001100110011);

  in = 0b0000000011111111;
  ASSERT_EQ(my_ntohs(in), 0b1111111100000000);

  in = 0b1100000000000011;
  ASSERT_EQ(my_ntohs(in), 0b0000001111000000);

  in = 0x0102;
  ASSERT_EQ(my_ntohs(in), 0x0201);

  in = 0xF00F;
  ASSERT_EQ(my_ntohs(in), 0x0FF0);
}

TEST(myNtohsShortTest, binarySimpleReverse) {
  unsigned short in = 0x0102;
  ASSERT_EQ(my_ntohs(in), 0x0201);
  ASSERT_EQ(htons(my_ntohs(in)), 0x0102);
  ASSERT_EQ(my_ntohs(my_ntohs(in)), 0x0102);

  in = 0b1100000000000011;
  ASSERT_EQ(my_ntohs(in), 0b0000001111000000);
  ASSERT_EQ(htons(my_ntohs(in)), 0b1100000000000011);
  ASSERT_EQ(my_ntohs(my_ntohs(in)), 0b1100000000000011);
}

TEST(myNtohsShortTest, exhaustive) {
  for (unsigned short i = 0; i < 0b1111111111111111; i += 0b1) {
    ASSERT_EQ(my_ntohs(i), ntohs(i));
  }
}

/* **************************************************
 * my_ntohl()
 * *************************************************/

TEST(myNtohlIntTest, binarySimple) {
  unsigned int in = 0b00000000000000000000000000000000;
  ASSERT_EQ(my_ntohl(in), 0b00000000000000000000000000000000);

  in = 0b00110011001100110011001100110011;
  ASSERT_EQ(my_ntohl(in), 0b00110011001100110011001100110011);

  in = 0b00000000000000001111111111111111;
  ASSERT_EQ(my_ntohl(in), 0b11111111111111110000000000000000);

  in = 0x99887766;
  ASSERT_EQ(my_ntohl(in), 0x66778899);

  in = 0x01FF01FF;
  ASSERT_EQ(my_ntohl(in), 0xFF01FF01);
}

TEST(myNtohlIntTest, exhaustive) {
  for (unsigned int i = 0; i < 0b1111111111111111; i += 0b1) {
    ASSERT_EQ(my_ntohl(i), ntohl(i));
  }
}

/* **************************************************
 * getHMS()
 * *************************************************/

TEST(getHMSTest, simpleDefined) {
  time_t epoch = 0;
  int hour, min, sec;

  getHMS(epoch, &hour, &min, &sec);
  ASSERT_EQ(sec, 0);
  ASSERT_EQ(min, 0);
  ASSERT_EQ(hour, 0);

  epoch = 3601;
  getHMS(epoch, &hour, &min, &sec);
  ASSERT_EQ(sec, 1);
  ASSERT_EQ(min, 0);
  ASSERT_EQ(hour, 1);

  epoch = 120;
  getHMS(epoch, &hour, &min, &sec);
  ASSERT_EQ(sec, 0);
  ASSERT_EQ(min, 2);
  ASSERT_EQ(hour, 0);
}

TEST(getHMSTest, simpleNow) {
  time_t epoch = time(0);
  int hour, min, sec;

  getHMS(epoch, &hour, &min, &sec);
  ASSERT_EQ(sec, gmtime(&epoch)->tm_sec);
  ASSERT_EQ(min, gmtime(&epoch)->tm_min);
  ASSERT_EQ(hour, gmtime(&epoch)->tm_hour);
}

TEST(getHMSTest, twoMonthLeapExhaustion) {
  time_t epoch;
  int hour, min, sec;

  // Try every second from 01/01/2012 to 03/01/2012
  for (int i = 1325376000; i < 1330560000; i++) {
    epoch = i;
    getHMS(epoch, &hour, &min, &sec);
    ASSERT_EQ(sec, gmtime(&epoch)->tm_sec);
    ASSERT_EQ(min, gmtime(&epoch)->tm_min);
    ASSERT_EQ(hour, gmtime(&epoch)->tm_hour);
  }
}

TEST(getHMSTest, thirtyYearExhaustion) {
  time_t epoch;
  int hour, min, sec;

  // Try random seconds from 01/01/1970 to 01/01/2012, random increments
  for (int i = 1; i < 1325376000; i += rand() % 10000) {
    epoch = i;
    getHMS(epoch, &hour, &min, &sec);
    ASSERT_EQ(sec, gmtime(&epoch)->tm_sec);
    ASSERT_EQ(min, gmtime(&epoch)->tm_min);
    ASSERT_EQ(hour, gmtime(&epoch)->tm_hour);
  }
}

/* **************************************************
 * getDayOfWeek()
 * *************************************************/

TEST(getDayOfWeekTest, simpleDefined) {
  time_t epoch = 0;

  ASSERT_EQ(getDayOfWeek(epoch), 4);

  epoch = 60 * 60 * 24; // Plus one day
  ASSERT_EQ(getDayOfWeek(epoch), 5);

  epoch = 60 * 60 * 24 * 7 - 1; // Plus one week minus one sec
  ASSERT_EQ(getDayOfWeek(epoch), 3);
}

TEST(getDayOfWeekTest, simpleNow) {
  time_t epoch = time(0);
  ASSERT_EQ(getDayOfWeek(epoch), gmtime(&epoch)->tm_wday);
}

TEST(getDayOfWeekTest, twoMonthLeapExhaustion) {
  time_t epoch;
  int hour, min, sec;

  // Try every second from 01/01/2012 to 03/01/2012
  for (int i = 1325376000; i < 1330560000; i++) {
    epoch = i;
    ASSERT_EQ(getDayOfWeek(epoch), gmtime(&epoch)->tm_wday);
  }
}

TEST(getDayOfWeekTest, thirtyYearExhaustion) {
  time_t epoch;
  int hour, min, sec;

  // Try random seconds from 01/01/1970 to 01/01/2012, random increments
  for (int i = 1; i < 1325376000; i += rand() % 10000) {
    epoch = i;
    ASSERT_EQ(getDayOfWeek(epoch), gmtime(&epoch)->tm_wday);
  }
}

/* **************************************************
 * getTime()
 * *************************************************/

TEST(getTimeTest, simpleDefined) {
  time_t epoch = 0;
  ASSERT_EQ(getTime(0, 0, 1970, 0, 0, 0), epoch);

  epoch = 60 * 60 * 24; // Plus one day
  ASSERT_EQ(getTime(0, 1, 1970, 0, 0, 0), epoch);

  epoch = 60 * 60 * 24 * 7 - 1; // Plus one week minus one sec
  ASSERT_EQ(getTime(0, 6, 1970, 23, 59, 59), epoch);

  epoch = 1679983200; // 2/27/23, 6:00:00
  ASSERT_EQ(getTime(2, 27, 2023, 6, 0, 0), epoch);
}

TEST(getTimeTest, simpleNow) {
  time_t epoch = time(0);
  ASSERT_EQ(getTime(gmtime(&epoch)->tm_mon, gmtime(&epoch)->tm_mday - 1,
                    gmtime(&epoch)->tm_year + 1900, gmtime(&epoch)->tm_hour,
                    gmtime(&epoch)->tm_min, gmtime(&epoch)->tm_sec),
            epoch);
}

TEST(getTimeTest, twoMonthLeapExhaustion) {
  time_t epoch;
  int hour, min, sec;

  // Try every second from 01/01/2012 to 03/01/2012
  for (int i = 1325376000; i < 1330560000; i++) {
    epoch = i;
    ASSERT_EQ(getTime(gmtime(&epoch)->tm_mon, gmtime(&epoch)->tm_mday - 1,
                      gmtime(&epoch)->tm_year + 1900, gmtime(&epoch)->tm_hour,
                      gmtime(&epoch)->tm_min, gmtime(&epoch)->tm_sec),
              epoch);
  }
}

TEST(getTimeTest, thirtyYearExhaustion) {
  time_t epoch;
  int hour, min, sec;

  // Try random seconds from 01/01/1970 to 01/01/2012, random increments
  for (int i = 1; i < 1325376000; i += rand() % 10000) {
    epoch = i;
    ASSERT_EQ(getTime(gmtime(&epoch)->tm_mon, gmtime(&epoch)->tm_mday - 1,
                      gmtime(&epoch)->tm_year + 1900, gmtime(&epoch)->tm_hour,
                      gmtime(&epoch)->tm_min, gmtime(&epoch)->tm_sec),
              epoch);
  }
}

/***************************************************/

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}