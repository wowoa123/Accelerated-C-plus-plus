#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <list>
#include <vector>

typedef std::list<double> contain;
//typedef std::vector<double> contain;

struct Student_info
{
    std::string name;
    double midterm, final;
    contain homework;
};

bool compare(const Student_info &, const Student_info &);
std::istream & read(std::istream &, Student_info &);
std::istream & read_hw(std::istream &, contain &);

#endif // STUDENT_INFO_H
