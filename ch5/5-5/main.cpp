#include <iostream>
#include <string>
#include "fill.h"

using namespace std;

int main()
{
    string s;
    vector<string> pic;
    while (cin >> s)
    {
        pic.push_back(s);
    }

    vector<string> f_pic = center(pic);

    for (vector<string>::const_iterator it = f_pic.begin(); it != f_pic.end(); ++it)
        cout << *it << endl;
    return 0;
}
