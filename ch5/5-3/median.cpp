#include "median.h"
#include <stdexcept>

using std::domain_error;

double median(contain vec)
{
    typedef contain::size_type con_sz;

    con_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    vec.sort();

    con_sz mid = size / 2;

    contain::iterator iter = vec.begin();
    for (con_sz i = 0; i != mid; ++i)
        ++iter;

    if ((size % 2) == 0)
        return (*iter + *(iter--)) / 2;
    else
        return *iter;
}
