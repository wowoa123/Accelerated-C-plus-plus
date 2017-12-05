#include "split.h"

std::vector<std::string> split(const std::string & s)
{
    std::vector<std::string> ret;
    typedef std::string::size_type str_sz;
    str_sz i = 0;

    while (i != s.size())
    {
        //忽略之前的空白
        while (i != s.size() && isspace(s[i]))
            ++i;

        //找到单词终结位置
        str_sz j = i;
        while (j != s.size() && !isspace(s[j]))
            ++j;

        if (i != j)
        {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }

    return ret;
}
