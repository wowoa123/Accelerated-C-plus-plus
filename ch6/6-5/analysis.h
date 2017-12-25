#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "student_info.h"
#include "grade.h"
#include "median.h"
#include <vector>
#include <algorithm>

double optimistic_median_analysis(const std::vector<Student_info> &students);

#endif // ANALYSIS_H
