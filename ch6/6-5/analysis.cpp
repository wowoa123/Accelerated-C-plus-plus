#include "analysis.h"

using std::vector;

double optimistic_median_analysis(const vector<Student_info> &students)
{
    vector<double> grades;

    std::transform(students.begin(), students.end(),
                   std::back_inserter(grades), optimistic_median);
    return median(grades);
}
