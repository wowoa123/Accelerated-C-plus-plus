#include "student_info.h"
#include <iostream>

using namespace std;

bool compare(const Student_info & x, const Student_info & y)
{
    return x.name < y.name;
}

istream & read(istream & is, Student_info & s)
{
    std::cout << "Enter students name: ";
    is >> s.name;

    std::cout << "Enter midterm and final grade:\n";
    is >> s.midterm >> s.final;

    std::cout << "Enter homework grade:\n";
    read_hw(is, s.homework);
    std::cout << std::endl;

    return is;
}

istream & read_hw(istream & is, contain &hw)
{
    if (is)
    {
        hw.clear();

        double x;
        while (is >> x)
            hw.push_back(x);

        is.clear();
    }
    return is;
}
