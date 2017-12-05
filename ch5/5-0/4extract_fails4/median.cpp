#include "median.h"
#include <stdexcept>

using namespace std;

double median(std::list<double> vec)
{
    typedef list<double>::size_type lis_sz;

    lis_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    vec.sort();

    lis_sz mid = size / 2;

    list<double>::iterator iter = vec.begin();
    for (lis_sz i = 0; i != mid; ++i)
        ++iter;

    if ((size % 2) == 0)
        return (*iter + *(iter--)) / 2;
    else
        return *iter;
}
