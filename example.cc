// CPlusPlusUnit Usage Example

// CPlusPlusUnit - C++ Unit testing TDD framework (github.com/cppunit/cppunit)
#include "cppunit.h"

// Class under test
class test_class {
    public: int calculate(){
        int n, m;
        std::cin >> n >> m;
        return n + m;
    }
};

// Test examples
class Cppunit_tests: public Cppunit {
    void single_test() {
        // Integral type match check
        CHECK(2 + 2, 4);

        // Boolean type check
        CHECKT(2 + 2 == 4);

        // String match check
        CHECKS("a" "b", "ab");

        // Stdin override example
        test_cin("2\n2");
        CHECK((new test_class)->calculate(), 4);
    }
};

// Invocation example (-ut switch)
int main(int argc, char *argv[]) {

    // Run unit tests only if -ut switch is used
    if (argc > 1 && !strcmp(argv[1], "-ut"))
        return (new Cppunit_tests)->run();

    std::cout << "NOTE: Use -ut switch to run cppunit tests";
    return 0;
}

