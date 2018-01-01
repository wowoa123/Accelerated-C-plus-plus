#include "xref.h"

using std::map;
using std::vector;
using std::string;
using std::istream;

map<string, vector<int> > xref(istream &in, bool &lines,
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
            ret[*it].push_back(line_number);
    }

    if (line_number == 1)
        lines = false;

    return ret;
}
