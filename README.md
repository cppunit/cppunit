# cppunit
Single source file C++ Unit testing TDD framework with the output message format like Python unittest.

No installation is required, just copy [cppunit.h](https://github.com/cppunit/cppunit/blob/master/cppunit.h) class definition into your source file and you are all set.

## License
Public Domain. For more information, please refer to <http://unlicense.org>

## Usage
For single source file programs:
1. Copy `Cppunit` class definition from [cppunit.h](https://github.com/cppunit/cppunit/blob/master/cppunit.h) into your source file
2. Make sure you have listed all required headers
2. It has to be located before `main()` function and unit tests

For larger projects:
1. Copy [cppunit.h](https://github.com/cppunit/cppunit/blob/master/cppunit.h) file into your project area
2. Include it as needed by `#include "cppunit.h"`

Next steps:
1. Create a new class derived from `Cppunit`
2. Redefine `test_list()` or `single_test()` (if only one test is needed) method of the derived class
3. Write tests by using `CHECK*` macros and `test_cin()` to mock user's `stdin` input stream
4. Instantiate and Call `run()` method of the derived class to invoke unit tests

See [example.cc](https://github.com/cppunit/cppunit/blob/master/example.cc) for a working example

## CHECK* macros
These macros will provide file, line and test name information in case of checking mismatch:

1. Integral type match check `CHECK(2 + 3, 4)`
2. Boolean type check `CHECKT(2 + 2 == 4)`
3. String type match check `CHECKS("a" "b", "ac")`

## Stdin input override
Cppunit will override user's `stdin` input stream. Use `test_cin()` method to provide user's mock input stream.

`test_cin("4 1\n-3 -3 -3 -3");`

This feature is very useful to test programs written for online judges like: codeforces.com, topcoder.com, spoj etc.

## Passed test output
Prints the number of checks passed and the elapsed time
```
...
--------------------------------------------------
Ran 3 checks in 0.002s

OK
```

## Failed test output
Error messages for all failed checks
```
F.F
==================================================
FAIL: single_test
--------------------------------------------------
File "cppunit.cc", line 51 in single_test
  Checking 2 + 3 == 4
  Error: "5" ! = "4"

==================================================
FAIL: single_test
--------------------------------------------------
File "cppunit.cc", line 57 in single_test
  Checking "a" "b" == "ac"
  Error: "ab" ! = "ac"

--------------------------------------------------
Ran 3 checks in 0.002s

FAILED (failures=2)
```
