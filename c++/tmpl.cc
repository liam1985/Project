#include <iostream>
#include <utility>

using namespace std;


template<typename T> 
class my_array {
public:
    explicit my_array(T&& t): value(t) {}
    explicit my_array(T& t): value(t) {}
    T get() const { return value; }
private:
    T value;
};


template<typename K, typename V, template<typename> typename C = my_array>
class Map
{
public:
    explicit Map(K k, V v): key(k), value(v) {}

//template<typename L, typename H, template<typename> typename M>
friend ostream& operator<< (ostream& os, const Map<K, V, C>& m);
friend ostream& operator<< (ostream& os, const Map<float, V, C>& m);

private:
    C<K> key;
    C<V> value;
};

template<typename K, typename V, template<typename> typename C = my_array>
ostream& operator<< (ostream& os, const Map<K, V, C>& m) {
    os << "key: " << m.key.get() << " value: " << m.value.get() << endl;
    return os;
}
/*
ostream& operator<< (ostream& os, const Map<int, float>& m) {
    os << "key: " << m.key.get() << " value: " << m.value.get() << endl;
    return os;
}*/

template<typename T1>
T1 add_one(T1 t) {
    return t + 1;
}

template<typename T>
struct MyStruct {
    T t;
};

template<typename T>
ostream& operator<< (ostream& os, const MyStruct<T>& m) {
    os << "MyStruct: " << m.t << endl;
}

template<typename T, template<typename> typename TT>
struct MyTmplStruct {
    MyTmplStruct(T&& v): t{v} {}
    TT<T> t;
};

template<typename T, template<typename> typename TT>
ostream& operator<< (ostream& os, const MyTmplStruct<T, TT>& m) {
    os << "MyTmplStruct: " << m.t ;
    return os;
}

template<typename T> struct eval;

template<template<typename, typename ...> class TT, typename T1, typename... Rest>
struct eval<TT<T1, Rest...>> {};


int main() {
    Map<int, float> m(1, 2.1);
    cout << m;
    cout << add_one(1) << endl;
    cout << add_one(3.5) << endl;

    MyStruct<int> m1{50};
    MyStruct<double> m2{80};
    cout << m1 << m2;

    MyTmplStruct<float, MyStruct> mt1(10);
    cout <<  mt1;
}
