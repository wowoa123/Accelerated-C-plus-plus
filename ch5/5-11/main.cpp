#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include "judge.h"
#include "del_word.h"

using namespace std;

int main()
{
    string s;
    list<string> words;

    while (cin >> s)
        words.push_back(s);

    new_list(words);

    cout << endl;
    string::size_type max = 0;
    for (list<string>::const_iterator it = words.begin(); it != words.end(); ++it)
    {
        cout << *it << endl;
        if (max < (*it).size())
        {
            max = (*it).size();
            s = *it;
        }
    }

    cout << "\nThe longest words is " << s << "." << endl;
    return 0;
}
