/*
 * Zeros to the Front
 *
 * Radison Akerman, February 2023
 * TIBCO Coding Assessment
 */

#include "zerosFront.h"

using namespace std;

/*
 * zerosToTheFront()
 * Moves all 0 values in the array to the front of the array.
 * Will return and do nothing if the array or count are out
 * of bounds. Runs in one pass and modifies the array in place.
 *
 * @param {int*} array - pointer to an array of integers
 * @param {int} count - number of elements in array
 */
void zerosToTheFront(int *array, int count) {
  // 1. Edge case, empty array or count out of bounds
  if (array == nullptr || count < 1)
    return;
  // 2. Loop through the array, starting at index 0
  int cursor = 0;
  int swap = 0;
  for (int i = 0; i < count; i++) {
    // Check for 0, if not 0, advance cursor
    if (array[i] != 0) {
      // Non-zero, advance cursor
      cursor++;
    } else {
      // Zero, swap at swap pos
      int temp = array[swap];
      array[swap] = array[i];
      array[i] = temp;
      swap++;
    }
  }
  // 3. Return, with zeros in place in array
  return;
}