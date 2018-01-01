#include "split.h"

using std::list;
using std::string;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

list<string> split(const string &str)
{
    typedef string::const_iterator iter;
    list<string> ret;

    iter i = str.begin();
    while (i != str.end())
    {
        //忽略前端空白
        i = std::find_if(i, str.end(), not_space);

        //找出结尾
        iter j = std::find_if(i, str.end(), space);

        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}
