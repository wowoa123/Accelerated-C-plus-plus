#include "del_word.h"

using std::list;
using std::string;

list<string> new_list(std::list<std::string> &li)
{
    list<string>::iterator it = li.begin();

    while (it != li.end())
    {
        if (judge_if_have(*it))
            it = li.erase(it);
        else
            ++it;
    }

    return li;
}
