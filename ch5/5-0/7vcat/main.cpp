#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> vcat(const vector<string> & top,
                    const vector<string> & bottom)
{
    //复制顶部图案
    vector<string> ret = top;

    //复制底部图案
    for (vector<string>::const_iterator it = bottom.begin();
         it != bottom.end(); ++it)
        ret.push_back(*it);
    //ret.insert(ret.end(), bottom.begin(), bottom.end());

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

    vector<string> v = vcat(v1, v2);

    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        cout << v[i] << endl;
    return 0;
}
