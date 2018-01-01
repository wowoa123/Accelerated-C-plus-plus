#include <iostream>
#include <map>
#include <string>
#include "xref.h"
#include "split.h"
#include <sstream>

using namespace std;

int main()
{
    map<string, vector<int> > ret = xref(cin);

    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); ++it)
    {
        stringstream ss;
        ss << it->first << " occurs on line(s): ";

        vector<int>::const_iterator line_it = it->second.begin();
        ss << *line_it;

        ++line_it;
        while (line_it != it->second.end())
        {
            ss << ", " << *line_it;
            ++line_it;
        }

        string output = ss.str();

        for (string::size_type i = 0; i != output.size(); ++i)
        {
            cout << output[i];

            if ((i + 1) % 80 == 0)
                cout << endl;
        }

        cout << endl;
    }
    return 0;
}
