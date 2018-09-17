#include <iostream>
#include <utility>
#include <type_traits>

#define UTIL_TEST
using namespace std;



struct Default { int foo() const { return 1; } };

struct NonDefault
{
    NonDefault(const NonDefault&) {}
    int foo() const { return 1; }
};

struct Soldier {
    int age;
};

int main() {
#ifdef MACRO
    cout << "count: " << __COUNTER__ << endl;
    cout << "count: " << __COUNTER__ << endl;
    cout << "count: " << __COUNTER__ << endl;
    cout << "count: " << __COUNTER__ << endl;
#endif

#ifdef UTIL_TEST
    decltype(std::declval<NonDefault>().foo()) n = 1;

    typedef std::integral_constant<int, 2> two_t;
    typedef std::integral_constant<int, 4> four_t;

    cout << "two_t.value:, " << two_t::value << endl;
#endif

    cout << "addr of Soldier::age: " << &Soldier::age << endl;

    return 0;
}
