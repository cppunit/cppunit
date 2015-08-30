# cppunit

Single source file C++ Unit testing framework with the output message format like Python unittest

https://github.com/cppunit/cppunit/blob/master/cppunit.cc

## Usage
1. Copy `Cppunit` class definition source code from [cppunit.cc](cppunit.cc) into your project
2. Derive a new class from Cppunit
3. Redefine `test_list()` or `single_test()` (if only one test is needed) method of the derived class
4. Write tests by using CHECK* macros
5. Call `run()` method of the derived class to invoke unit tests

## Check macros

1. Integral type match check `CHECK(2 + 3, 4)`
2. Boolean type check `CHECKT(2 + 2 == 4)`
3. String type match check `CHECKS("a" "b", "ac")`

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

## License
Public Domain. For more information, please refer to <http://unlicense.org>
