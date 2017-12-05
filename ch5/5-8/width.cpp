#include "width.h"
#include <algorithm>

std::string::size_type width(const std::vector<std::string> &v)
{
    std::string::size_type maxlen = 0;
    for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
        maxlen = std::max(maxlen, v[i].size());
    return maxlen;
}
