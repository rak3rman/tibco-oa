# TIBCO Coding Assessment

## Usage
In order to get up and running with the test cases, make sure C++ is installed and the following libraries are available globally on your machine:

```
#include "gtest/gtest.h"
#include <arpa/inet.h>
#include <bits/stdc++.h>
```

Jetbrains Fleet was used as an IDE to develop this project, where run commands are already ready to go ("Make Tests", "Run Tests").
Otherwise, the test cases can be compiled and executed on the command line:

```
make && ./suite
```

## Structure
All source code is available in the `~/src~` folder, including header files.
Here are a few key files to be aware of:

- `src/byteOrdering.cpp` Byte Ordering
- `src/epochParse.cpp` Epoch Parsing
- `src/zerosFront.cpp` Zeros to the Front
- `tests.cpp` Test Cases
- `CMakeLists.txt` CMake File

## Topic Questions
> Of course there are mirror routines htons() and htonl() to go from "host" to "network" - how do these compare to the ntoh* routines? Are the conversions done by the ntoh* routines reversible or does the library have to include different code for the hton* variants - think about that for a bit (this is an essay question, you don't have to write those routines).

The ntoh* routines are effectively identical to the hton* routines, and indeed reversible.
This is demonstrated programmatically in the `tests.cpp` file, line 224 (test case "myNtohsShortTest.binarySimpleReverse").

```
ASSERT_EQ(my_ntohs(in), 0x0201);
ASSERT_EQ(htons(my_ntohs(in)), 0x0102);
ASSERT_EQ(my_ntohs(my_ntohs(in)), 0x0102);
```

This particular test case passes, and it makes complete sense.
Consider the hex string 0xFF00.
If we run my_ntohs() on the string, it transforms to 0x00FF (now in "host" order).
But if we want to flip it back to "network" order (0xFF00), it is very simple, flip the bits again in byte order = 0xFF00.
Therefore, my_ntohs() achieves the same effect as "htons()" would.
This is proven on line 227 (sample line 2) and 228 (sample line 3) in the test cases, wrapping my_ntohs() in itself returns the same as htons() wrapped around my_ntohs (network -> host -> network).

> The functions are declared as unsigned above, is this important? What if they aren't declared that way?

Declaring the functions as unsigned is incredibly important (in most cases).
Keep in mind that marking an int or short or any number as negative or positive requires storing that distinction and shifts the representation of those numbers (if we had unsigned range 0 to 100, now it could be -50 to 50).
Typically this distinction can have a huge effect on the binary representation of a number, say two's complement for example.
In any case, some bit(s) would need to be set and simply flipping a number from little to big endian would introduce a whole suite of complexities depending on how you intend to read the data.
If you plan to convert from host to network, and from network to host, then you may be able to avoid this unsigned problem if you choose the right pos/neg binary representation.
But if you plan to only convert fron host to network (say try to read a number backwards), then you run into a problem that is a tad complicated.

