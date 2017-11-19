#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please enter first number: ";

    int i = 0;
    cin >> i;

    cout << "Please enter second number: ";

    int j = 0;
    cin >> j;

    if (i < j)
        cout << j;
    else
        cout << i;
    return 0;
}
