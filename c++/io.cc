#include <string>
#include <sstream>
#include <iostream>


using namespace std;


int main() {
    string str("Hello World!");
    istringstream istr(str);
    string tmp, tmp1;
    istr >> tmp >> tmp1;
    cout << tmp << " " << tmp1 << endl;
    // print: Hello World!

    istr.str(string("test 123"));
    if (istr.eof()) {
        cout << "[Eof reached]" << endl;
        istr.seekg(0, istr.beg);    
    }
    int i1;
    istr >> tmp >> i1;
    cout << tmp << " " << i1 << endl;
    cout << "istr.str: " << istr.str() << endl;
}
