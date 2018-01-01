#include "grammer.h"

using std::vector;
using std::string;

Grammer read_grammer(std::istream &in)
{
    Grammer ret;
    string line;

    while (std::getline(in, line))
    {
        vector<string> entry = split(line);

        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}

vector<string> gen_sentence(const Grammer &g)
{
    vector<string> rules;
    vector<string> sentence;
    rules.push_back("<sentence>");

    //检查完一个规则就删除
    while (!rules.empty())
    {
        string rule = rules.back();
        rules.pop_back();
        gen_aux(g, rule, rules, sentence);
    }
    return sentence;
}

bool bracketed(const string &s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammer &g, const string &word,
             vector<string> &rules, vector<string> &sentence)
{
    if (!bracketed(word))
    {
        sentence.push_back(word);
    }
    else
    {
        Grammer::const_iterator it = g.find(word);
        if (it == g.end())
            throw std::logic_error("empty rule");

        const Rule_collection &c = it->second;

        const Rule &r = c[nrand(c.size())];

        //反向压入规则，使顺序正确
        for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
            rules.push_back(*i);
    }
}

int nrand(int n)
{
    if (n <= 0 || n >= RAND_MAX)
        throw std::domain_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do
    {
        r = rand() / bucket_size;
    } while (r >= n);

    return r;
}
