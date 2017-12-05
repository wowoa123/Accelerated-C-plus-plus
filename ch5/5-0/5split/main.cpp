#include <string>
#include <vector>
#include <iostream>
#include "split.h"

using namespace std;

int main()
{
    string s;
    //读并分割每行输入
    while (getline(cin, s))
    {
        vector<string> v = split(s);

        //输出v中单词
        for (vector<string>::size_type i  = 0; i != v.size(); ++i)
            cout << v[i] << endl;
    }

    return 0;
}

/*int main()
{
    string s;
    while (cin >> s)
        cout << s << endl;
    return 0;
}*/
