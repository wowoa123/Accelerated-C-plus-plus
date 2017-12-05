#include <iostream>
#include <vector>
#include <string>
#include "width.h"

using namespace std;

vector<string> hcat(const vector<string> & left,
                    const vector<string> & right)
{
    vector<string> ret;

    //在两幅图案之间留一个空格
    string::size_type width1 = width(left) + 1;

    vector<string>::size_type i = 0, j = 0;

    string s = "";
    while (i != left.size() || j != right.size())
    {
        //如果左侧还有行，则复制
        if (i != left.size())
            s = left[i++];

        //填充至合适长度
        //长度为负，抛出异常
        s += string(width1 - s.size(), ' ');

        //如果右侧还有行，则复制
        if (j != right.size())
            s += right[j++];

        ret.push_back(s);
    }

    return ret;
}

int main()
{
    vector<string> v1;
    vector<string> v2;

    v1.push_back("111");
    v1.push_back("222");

    v2.push_back("333");
    v2.push_back("444");
    v2.push_back("555");

    vector<string> v = hcat(v1, v2);

    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        cout << v[i] << endl;
    return 0;
}
