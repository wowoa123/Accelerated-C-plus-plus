#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int length = 5;
    const int width = 4;

    for (int r = 0; r != length; ++r)
    {
        int c = 0;
        while (c != length)
        {
            if (r == 0 || r == length - 1 ||
                c == 0 || c == length - 1)
                cout << "*";
            else
                cout << " ";
            ++c;
        }
        cout << endl;
    }

    cout << endl;

    for (int r = 0; r != width; ++r)
    {
        int c = 0;
        while (c != length)
        {
            if (r == 0 || r == width - 1 ||
                c == 0 || c == length - 1)
                cout << "*";
            else
                cout << " ";
            ++c;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i != length; ++i)
    {
        for (int j = 0; j != i; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
