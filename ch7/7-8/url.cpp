#include "url.h"

using std::vector;
using std::string;

vector<string> find_urls(const std::string &s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    //检查输入
    while (b != e)
    {
        //查找紧跟着://的字母
        b = url_beg(b, e);
        //查找成功
        if (b != e)
        {
            //获取url其余部分
            iter after = url_end(b, e);

            ret.push_back(string(b, after));

            //推进b查找其他url
            b = after;
        }
    }
    return ret;
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
    return std::find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!'(),";

    return !(isalnum(c) ||
             std::find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";

    typedef string::const_iterator iter;

    iter i = b;

    while ((i = std::search(i, e, sep.begin(), sep.end())) != e)
    {
        //确保分隔符不是唯一的符号
        if (i != b && i + sep.size() != e)
        {
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            //检查分隔符前后至少有一个字符
            if (beg != i && i + sep.size() != e
                    && !not_url_char(i[sep.size()]))
                return beg;
        }

        //如果分隔符不是url一部分
        if (i != e)
            i += sep.size();
    }
    return e;
}
