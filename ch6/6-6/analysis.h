#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "student_info.h"
#include "grade.h"
#include "median.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

double grade_aux(const Student_info &s);
double average(const std::vector<double> &v);
double optimistic_median(const Student_info &s);
double analysis(const std::vector<Student_info> &students);

#endif // ANALYSIS_H
