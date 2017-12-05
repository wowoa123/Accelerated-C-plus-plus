#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include "palin.h"

using namespace std;

int main()
{
    string s;
    list<string> li;

    while (cin >> s)
        li.push_back(s);

    list<string> result = palin(li);

    cout << endl;
    string::size_type max = 0;
    for (list<string>::const_iterator it = result.begin(); it != result.end(); ++it)
    {
        cout << *it << endl;
        if (max < (*it).size())
        {
            max = (*it).size();
            s = *it;
        }
    }
    cout << endl << "The longest word is " << s << "." << endl;
    return 0;
}
