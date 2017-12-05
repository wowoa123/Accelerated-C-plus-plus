#include <iostream>
#include <vector>
#include <string>
#include "split.h"
#include <cstdlib>
#include "convert.h"
#include "sort.h"
#include <algorithm>

using namespace std;

int main()
{
    vector<string> v1;
    string s;

    while (getline(cin, s))
    {
        v1.push_back(s);
    }

    //保存最终结果
    vector<string> last;
    //轮转单词
    typedef vector<string>::size_type vec_sz;
    for (vec_sz i = 0; i != v1.size(); ++i)
    {
        vector<string> tmp;
        //分离单词
        tmp = split(v1[i]);
        vec_sz len = tmp.size();

        for (vec_sz j = 0; j != len; ++j)
        {
            string sign = "";
            if (j != 0)
            {
                //单词前移
                s = tmp[0];
                for (vec_sz k = 0; k != len - 1; ++k)
                {
                    tmp[k] = tmp[k + 1];
                }
                tmp[len - 1] = s;
            }

            //添加分隔符指出反转几次
            s = string(NumToStr(j)) + tmp[0];
            sign = s;

            s = "";
            //合成句子
            for (vec_sz k = 0; k != len; ++k)
            {
                if (k == 0)
                {
                    s += sign;
                    s += " ";
                }
                else
                {
                    s += tmp[k];
                    s += " ";
                }
            }
            last.push_back(s);
        }
    }

    sort(last.begin(), last.end(), compare);

    for (vec_sz i = 0; i != last.size(); ++i)
    {
        //获取反转次数
        int count = StrToNum(last[i]);

        vector<string> tmp;
        //分离单词
        if (count < 10)
            tmp = split(last[i].substr(1));
        else
            tmp = split(last[i].substr(2));
        vec_sz len = tmp.size();

        //输出索引
        cout << tmp[0] << "   ";

        for (int j = 0; j != count; ++j)
        {
            s = tmp[len - 1];
            //单词后移
            for (vec_sz k = len - 1; k != 0; --k)
            {
                tmp[k] = tmp[k - 1];
            }
            tmp[0] = s;
        }

        s = "";
        for (vec_sz k = 0; k != len; ++k)
        {
            s += tmp[k];
            s += " ";
        }

        last[i] = s;
        cout << last[i] << endl;
    }

    return 0;
}
