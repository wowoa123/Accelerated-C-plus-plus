#include "sort.h"

using std::string;

bool compare(string s1, string s2)
{
    int def = 1;
    //确认第二个是不是字母
    if (isalpha(s1[def]) && isalpha(s2[def]))
    {
        string tmp1, tmp2;
        tmp1 = s1.substr(def);
        tmp2 = s2.substr(def);
        return tmp1 < tmp2;
    }
    else if (isalpha(s1[def]) && isdigit(s2[def]))
    {
        string tmp1, tmp2;
        tmp1 = s1.substr(def);
        tmp2 = s2.substr(def + 1);
        return tmp1 < tmp2;
    }
    else if (isdigit(s1[def]) && isalpha(s2[def]))
    {
        string tmp1, tmp2;
        tmp1 = s1.substr(def + 1);
        tmp2 = s2.substr(def);
        return tmp1 < tmp2;
    }
    else
    {
        string tmp1, tmp2;
        tmp1 = s1.substr(def + 1);
        tmp2 = s2.substr(def + 1);
        return tmp1 < tmp2;
    }
}
