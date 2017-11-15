#include <iomanip>
#include <iostream>

using namespace std;

int width(int i)
{
    int w = 0;
    while (i != 0)
    {
        i /= 10;
        ++w;
    }

    return w;
}

int main()
{
    double max = 999;
    for (double i = 0; i != 999; ++i)
    {
        cout << setw(width(max) + 2) << left << i << i * i << endl;
    }

    return 0;
}
