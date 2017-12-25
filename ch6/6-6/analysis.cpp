#include "analysis.h"

using std::vector;

double grade_aux(const Student_info &s)
{
    try {
        return grade(s);
    } catch (std::domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double average(const vector<double> &v)
{
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double optimistic_median(const Student_info &s)
{
    vector<double> nonzero;
    std::remove_copy(s.homework.begin(), s.homework.end(),
                     std::back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

double analysis(const vector<Student_info> &students)
{
    vector<double> grades;

    std::transform(students.begin(), students.end(),
                   std::back_inserter(grades), optimistic_median);
    return median(grades);
}
