#include <typeinfo>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;


struct Base {};
struct Derived : Base {};

struct Base2 { virtual void foo() {} };
struct Derived2 : Base2 {};


int main() {
    int myint = 50;
    string mystr = "string";
    double *mydoubleptr = nullptr;

    std::cout << "myint type: " << typeid(myint).name() << endl;
    std::cout << "mystr type: " << typeid(mystr).name() << endl;
    std::cout << "mydoubleptr type: " << typeid(mydoubleptr).name() << endl;

    const std::type_info &r1 = typeid(cout << myint);
    cout << endl << "cout << myint has type: " << r1.name() << endl;

    const std::type_info &r2 = typeid(printf("%d\n", myint));
    cout << "printf(\"%d\\n\",myint) has type: " << r2.name() << endl;
}
