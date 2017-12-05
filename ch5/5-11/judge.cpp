#include "judge.h"

using std::string;

bool judge_if_have(const std::string &s)
{
    bool flag = false;
    char set[12] = {'b', 'd', 'f', 'h', 'k', 'l', 't',
                'g', 'j', 'p', 'q', 'y'};
    for (string::size_type i = 0; i != s.size(); ++i)
    {
        for (int j = 0; j != 12; ++j)
        {
            if (s[i] == set[j])
            {
                flag = true;
                break;
            }
        }
    }

    return flag;
}
