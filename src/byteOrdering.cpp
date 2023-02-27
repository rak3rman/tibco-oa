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
 * order to "host" order.
 *
 * @param {unsigned short} in - short value in "network" order
 * @returns {unsigned short} - short value in "host" order
 */
unsigned short my_ntohs(unsigned short in) {
    return in;
}

/*
 * my_ntohs()
 * Network to host short. Converts a int value from "network"
 * order to "host" order.
 *
 * @param {unsigned int} in - int value in "network" order
 * @returns {unsigned int} - int value in "host" order
 */
unsigned int my_ntohl(unsigned int in) {
    return in;
}