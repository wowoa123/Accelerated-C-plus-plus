#include <iostream>
#include <map>
#include <string>
#include "grammer.h"
#include "split.h"

using namespace std;

int main()
{
    vector<string> sentence = gen_sentence(read_grammer(cin));

    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty())
    {
        cout << *it;
        ++it;
    }

    while (it != sentence.end())
    {
        cout << " " << *it;
        ++it;
    }

    cout << endl;
    return 0;
}
