#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include "student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const Student_info &);

#endif // GRADE_H
