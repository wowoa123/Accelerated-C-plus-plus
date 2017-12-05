#include "fill.h"

using std::vector;
using std::string;

string::size_type maxlen(const vector<string> & v)
{
    string::size_type max = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        if (max < v[i].size())
            max = v[i].size();
    }
    return max;
}

vector<string> center(const vector<string> & v)
{
    string::size_type max = maxlen(v);
    vector<string> r;
    for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        string::size_type len = (*it).size();
        string::size_type mid = (max - len) / 2;
        string result = "";
        if ((max - len) % 2 != 0)
        {
            string tmp(mid, '*');
            result = tmp + *it + tmp + "*";
            r.push_back(result);
        }
        else
        {
            string tmp(mid, '*');
            result = tmp + *it + tmp;
            r.push_back(result);
        }
    }
    return r;
}
