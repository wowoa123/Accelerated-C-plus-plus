#include "student_info.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::istream;

bool compare(const Student_info & x, const Student_info & y)
{
    return x.name < y.name;
}

istream & read(istream & is, Student_info & s)
{
    cout << "Enter students name: ";
    is >> s.name;

    cout << "Enter midterm and final grade:\n";
    is >> s.grade.midterm >> s.grade.final;

    cout << "Enter homework grade:\n";
    read_hw(is, s.grade.homework);
    cout << endl;

    return is;
}

istream & read_hw(istream & is, vector<double> & hw)
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
