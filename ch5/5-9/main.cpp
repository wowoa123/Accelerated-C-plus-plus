#include <iostream>
#include <list>
#include <string>
#include <cctype>

using namespace std;

list<string> select(list<string> & li)
{
    list<string> lower;
    list<string>::iterator it = li.begin();

    while (it != li.end())
    {
        if (islower((*it)[0]))
        {
            lower.push_back(*it);
            it = li.erase(it);
        }
        else
            ++it;
    }

    return lower;
}

int main()
{
    string s;
    list<string> li;

    while (cin >> s)
        li.push_back(s);

    list<string> lower = select(li);

    cout << "Lower:\n";
    for (list<string>::const_iterator it = lower.begin(); it != lower.end(); ++it)
        cout << *it << endl;

    cout << endl;

    cout << "Upper:\n";
    for (list<string>::const_iterator it = li.begin(); it != li.end(); ++it)
        cout << *it << endl;
    return 0;
}
