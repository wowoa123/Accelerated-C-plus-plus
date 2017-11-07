#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {54, 85, 102, 5100,
                     35, 48, 64, 855,
                     31, 5, 499, 350};
    typedef vector<int>::size_type vec_sz;
    vec_sz count = v.size() / 4;

    sort(v.rbegin(), v.rend());

    for (int i, j = 0; i < count; ++i)
    {
        for (int k = 4 * i + 1; k < 4 * (i + 1); ++k)
        {
            if (k == 4 * i + 1)
                cout << "part " << ++j << ": ";
            cout << v[k] << " ";
        }
        cout << endl;
    }

    return 0;
}
