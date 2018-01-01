#include <iostream>
#include <map>
#include <string>
#include "grammer.h"
#include "split.h"
#include <list>

using namespace std;

int main()
{
    list<string> sentence = gen_sentence(read_grammer(cin));

    list<string>::const_iterator it = sentence.begin();
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
