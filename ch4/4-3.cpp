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
    int max = 999;
    for (int i = 0; i != 999; ++i)
    {
        cout << setw(width(max) + 2) << left << i << i * i << endl;
    }

    return 0;
}
