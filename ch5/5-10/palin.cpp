#include "palin.h"

using std::string;
using std::list;

string reverse(const std::string &s)
{
    string tmp;
    string::size_type len = s.size();
    for (string::size_type i = 0; i != len; ++i)
        tmp += s[len - i - 1];

    return tmp;
}

list<string> palin(const std::list<std::string> &li)
{
    list<string> r;

    for (list<string>::const_iterator it = li.begin(); it != li.end(); ++it)
    {
        if ((*it) == reverse(*it))
            r.push_back(*it);
    }

    return r;
}
