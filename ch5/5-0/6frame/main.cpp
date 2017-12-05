#include <iostream>
#include <vector>
#include <string>
#include "frame.h"
#include "split.h"

using namespace std;

int main()
{
    string s;
    //读并分割每行输入
    getline(cin, s);
    vector<string> v = split(s);

    vector<string> ret = frame(v);

    for (vector<string>::size_type i = 0; i != ret.size(); ++i)
        cout << ret[i] << endl;
    return 0;
}
