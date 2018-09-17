#include <any>
#include <iostream>

using namespace std;


int main() {
    std::any a1 = 5;
    cout << "a1 type: " << a1.type() << endl;
}
