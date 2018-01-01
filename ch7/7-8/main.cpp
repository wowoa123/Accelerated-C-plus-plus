#include <iostream>
#include <map>
#include <string>
#include "xref.h"
#include "url.h"

using namespace std;

int main()
{
    bool lines = true;
    map<string, vector<int> > ret = xref(cin, lines);

    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); ++it)
    {
        if (lines)
            cout << it->first << " occurs on lines: ";
        else
            cout << it->first << " occurs on line: ";

        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;

        ++line_it;
        while (line_it != it->second.end())
        {
            cout << ", " << *line_it;
            ++line_it;
        }

        cout << endl;
    }
    return 0;
}
