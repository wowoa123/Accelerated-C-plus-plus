#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    v.resize(10);
    copy(u.begin(), u.end(), v.begin());
    //copy(u.begin(), u.end(), back_inserter(v.begin()));

    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    return 0;
}
