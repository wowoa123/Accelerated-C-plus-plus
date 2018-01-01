#include <iostream>
#include <map>
#include <string>

using namespace std;

int max_size(const map<string, int> &m)
{
    int i = 0;
    for (map<string, int>::const_iterator it = m.begin();
         it != m.end(); ++it)
    {
        if (i < it->second)
            i = it->second;
    }

    return i + 1;
}

int main()
{
    string s;
    map<string, int> counters;

    while (cin >> s)
        ++counters[s];

    for (int i = 0; i != max_size(counters); ++i)
    {
        for (map<string, int>::const_iterator it = counters.begin();
             it != counters.end(); ++it)
        {
            if (it->second == i)
                cout << it->first << "\t" << it->second << endl;
        }
    }

    return 0;
}
