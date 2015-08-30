# cppunit

Single source file C++ Unit testing TDD framework with the output message format like Python unittest.

No installation is required, just copy [cppunit.cc](cppunit.cc) class definition into your source file and you are all set.

## License
Public Domain. For more information, please refer to <http://unlicense.org>

## Usage
1. Copy `Cppunit` class definition source code from [cppunit.cc](cppunit.cc) into your project
2. Derive a new class from `Cppunit`
3. Redefine `test_list()` or `single_test()` (if only one test is needed) method of the derived class
4. Write tests by using `CHECK*` macros and `test_cin()` to mock user's `stdin` input stream
5. Call `run()` method of the derived class to invoke unit tests

See [cppunit.cc](cppunit.cc) for a working example

## CHECK* macros
These macros will provide file, line and test name information in case of checking mismatch:

1. Integral type match check `CHECK(2 + 3, 4)`
2. Boolean type check `CHECKT(2 + 2 == 4)`
3. String type match check `CHECKS("a" "b", "ac")`

## Stdin input override
Cppunit will override user's `stdin` input stream. Use `test_cin()` method to provide user's mock input stream.

`test_cin("4 1\n-3 -3 -3 -3");`

This feature is very useful to test programs written for online judges like: codeforces.com, topcoder.com, spoj etc.

## Passing test output
```
...
--------------------------------------------------
Ran 3 checks in 0.002s

OK
```

## Failing test output
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
