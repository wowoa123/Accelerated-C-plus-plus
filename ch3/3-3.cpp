#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Enter words:\n";

    vector<string> v;
    string word;
    typedef vector<string>::size_type vec_sz;

    while (cin >> word)
        v.push_back(word);

    sort(v.begin(), v.end());

    for (vec_sz i = 0; i != v.size(); )
    {
        int count = 0;
        cout << v[i] << ": ";
        //防止越界
        for (vec_sz j = i; j != v.size() && v[j] == v[i]; ++j)
            ++count;
        cout << count << endl;
        i += count;
    }

    return 0;
}
