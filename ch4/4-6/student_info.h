#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>

struct Grade
{
    double midterm;
    double final;
    std::vector<double> homework;
};

struct Student_info
{
    std::string name;
    Grade grade;
    double final_grade;
};

bool compare(const Student_info &, const Student_info &);
std::istream & read(std::istream &, Student_info &);
std::istream & read_hw(std::istream &, std::vector<double> &);

#endif // STUDENT_INFO_H
