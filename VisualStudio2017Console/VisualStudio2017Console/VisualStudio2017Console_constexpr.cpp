#include <stdio.h>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <utility>
#include <map>
#include <string>

// compile time constant expression. C++11
// with 'const' it's not possible.
// jintaeks on 2017-10-29_19-14
//
constexpr int get_five() { return 5; }

struct person
{
    std::int64_t&   get_id() { return id_; }
    std::string&    get_name() { return name_; }
private:
    std::int64_t    id_;
    std::string     name_;
};

// with C++17
//
template<std::size_t I>
auto& get(person& p)
{
    if constexpr (I == 0)
        return p.get_id();
    else if constexpr (I == 1)
        return p.get_name();
}

// before C++17
//
//template<std::size_t I>
//auto& get(person& p);
//
//template<>
//auto& get<0>(person& p)
//{
//	return p.get_id();
//}
//
//template<>
//auto& get<1>(person& p)
//{
//	return p.get_name();
//}

constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
}

int main()
{
    int some_value[get_five() + 7]; // Create an array of 12 integers. Valid C++11	return 0;
    //int some_value[(int)exp(1, 2) + 7];
    person p;
    get<0>(p) = 1;
    get<1>(p) = "hello";
    std::cout << get<1>(p) << std::endl;
}
