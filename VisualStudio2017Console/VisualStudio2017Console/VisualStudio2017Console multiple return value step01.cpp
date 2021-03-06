#include <tuple>
#include <string>
#include <iostream>

//using namespace std;

std::tuple<int, std::string, double> f()
{
    int i{ 108 };
    std::string s{ "Some text" };
    double d{ .01 };
    return { i,s,d };
}

int main()
{
    auto t = f();
    std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << std::endl;

    // --or--

    int myval;
    std::string myname;
    double mydecimal;
    std::tie(myval, myname, mydecimal) = f();
    std::cout << myval << " " << myname << " " << mydecimal << std::endl;

    return 0;
}