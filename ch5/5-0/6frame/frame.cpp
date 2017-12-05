#include "frame.h"
#include <algorithm>

std::string::size_type width(const std::vector<std::string> &v)
{
    std::string::size_type maxlen = 0;
    for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
        maxlen = std::max(maxlen, v[i].size());
    return maxlen;
}

std::vector<std::string> frame(const std::vector<std::string> &v)
{
    std::vector<std::string> ret;
    std::string::size_type maxlen = width(v);
    std::string border(maxlen + 4, '*');

    //输出顶部边框
    ret.push_back(border);

    //输出内部行，每一行用一个星号和一个空格框起
    for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
    {
        ret.push_back("* " + v[i] + std::string(maxlen - v[i].size() + 1, ' ') + "*");
    }

    //输出底部边框
    ret.push_back(border);

    return ret;
}
