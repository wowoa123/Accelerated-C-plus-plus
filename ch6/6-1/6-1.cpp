#include "6-1.h"

using std::vector;
using std::string;

string::size_type width(const vector<string> &v)
{
    vector<string>::const_iterator iter;
    string::size_type maxlen = 0;
    for (iter = v.begin(); iter != v.end(); ++iter)
    {
        if (maxlen < (*iter).size())
            maxlen = (*iter).size();
    }
    return maxlen;
}

vector<string> frame(const vector<string> &v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        ret.push_back("*" + (*it) + string(maxlen - (*it).size(), ' ') + "*");
    }

    ret.push_back(border);
    return ret;
}

vector<string> hcat(const vector<string> &left,
                    const vector<string> &right)
{
    vector<string> ret;

    string::size_type width1 = width(left) + 1;

    vector<string>::const_iterator l = left.begin(), r = right.begin();

    while (l != left.end() || r != right.end())
    {
        string s;

        if (l != left.end())
        {
            s = *l;
            ++l;
        }

        s += string(width1 - s.size(), ' ');

        if (r != right.end())
        {
            s += *r;
            ++r;
        }

        ret.push_back(s);
    }

    return ret;
}
