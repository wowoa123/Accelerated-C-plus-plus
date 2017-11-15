#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> v;

    double x;
    while(cin >> x)
        v.push_back(x);

    double sum = 0;
    typedef vector<double>::size_type vec_sz;
    for (vec_sz i = 0; i != v.size(); ++i)
        sum += v[i];

    cout << endl << sum / v.size();
    return 0;
}
