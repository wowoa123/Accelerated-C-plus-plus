#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    typedef vector<string>::size_type vec_sz;

    cout << "Enter word(s): ";

    vector<string> str_v;
    string x;

    while (cin >> x)
        str_v.push_back(x);

    vec_sz min = 0;
    vec_sz max = 0;
    for (vec_sz i = 0; i != str_v.size(); ++i)
    {
        if (str_v[min].size() > str_v[i].size())
            min = i;
        if (str_v[max].size() < str_v[i].size())
            max = i;
    }

    cout << "the shortest is " << str_v[min].size() << endl;
    cout << "the longest is " << str_v[max].size() << endl;

    return 0;
}
