/*
 * Byte Ordering
 *
 * Radison Akerman, February 2023
 * TIBCO Coding Assessment
 */

#include "byteOrdering.h"

/*
 * my_ntohs()
 * Network to host short. Converts a short value from "network"
 * order to "host" order. Since we are dealing with memory, we
 * *shouldn't* error out or return as long as some short is passed.
 *
 * @param {unsigned short} in - short value in "network" order
 * @returns {unsigned short} - short value in "host" order
 */
unsigned short my_ntohs(unsigned short in) {
  // 1. "Divide" incoming short into individual bytes, using mask
  unsigned short byteA = in & 0x00FF;
  unsigned short byteB = in & 0xFF00;
  // 2. Shift (reverse) bytes, concat and return final short
  return (byteB >> 8) & 0x00FF | (byteA << 8) & 0xFF00;
}

/*
 * my_ntohl()
 * Network to host int. Converts a int value from "network"
 * order to "host" order. Since we are dealing with memory, we
 * *shouldn't* error out or return as long as some int is passed.
 *
 * @param {unsigned int} in - int value in "network" order
 * @returns {unsigned int} - int value in "host" order
 */
unsigned int my_ntohl(unsigned int in) {
  // 1. "Divide" incoming int into individual bytes, using mask
  unsigned int byteA = in & 0x000000FF;
  unsigned int byteB = in & 0x0000FF00;
  unsigned int byteC = in & 0x00FF0000;
  unsigned int byteD = in & 0xFF000000;
  // 2. Shift (reverse) bytes, concat and return final int
  return (byteD >> 24) & 0x000000FF | (byteC >> 8) & 0x0000FF00 |
         (byteB << 8) & 0x00FF0000 | (byteA << 24) & 0xFF000000;
}