#include "xref.h"

using std::map;
using std::vector;
using std::string;
using std::istream;

map<string, vector<int> > xref(istream &in,
                               vector<string> find_words(const string&))
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while (std::getline(in, line))
    {
        ++line_number;

        vector<string> words = find_words(line);

        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it)
        {
            map<string, vector<int> >::const_iterator iter = ret.find(*it);
            if (iter != ret.end())
            {
                //检查行号是否重复
                vector<int>::const_iterator vec_it = (iter->second).begin();
                while (vec_it != (iter->second).end())
                {
                    if ((*vec_it) == line_number)
                        break;
                    ++vec_it;
                }
                if (vec_it == (iter->second).end())
                    ret[*it].push_back(line_number);
            }
            else
            {
                ret[*it].push_back(line_number);
            }
        }
    }
    return ret;
}
