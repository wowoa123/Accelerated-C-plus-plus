#include "convert.h"
#include <iostream>

std::string NumToStr(int n)
{
    char tmp[10];
    sprintf(tmp, "%d", n);
    return tmp;
}

int StrToNum(std::string s)
{
    std::string s1 = s.substr(0, 1);
    std::string s2 = s.substr(0, 2);
    char tmp[10];
    int n;
    if (isalpha(s[1]))
    {
        strcpy(tmp, s1.c_str());
        sscanf(tmp, "%d", &n);
    }
    else
    {
        strcpy(tmp, s2.c_str());
        sscanf(tmp, "%d", &n);
    }
    return n;
}
