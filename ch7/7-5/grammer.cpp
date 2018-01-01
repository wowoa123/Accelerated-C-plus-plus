#include "grammer.h"

using std::list;
using std::string;

Grammer read_grammer(std::istream &in)
{
    Grammer ret;
    string line;

    while (std::getline(in, line))
    {
        list<string> entry = split(line);

        if (!entry.empty())
            ret[*(entry.begin())].push_back(Rule(++(entry.begin()), entry.end()));
    }
    return ret;
}

list<string> gen_sentence(const Grammer &g)
{
    list<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

bool bracketed(const string &s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammer &g, const string &word, list<string> &ret)
{
    if (!bracketed(word))
    {
        ret.push_back(word);
    }
    else
    {
        Grammer::const_iterator it = g.find(word);
        if (it == g.end())
            throw std::logic_error("empty rule");

        const Rule_collection &c = it->second;

        const Rule &r = c[nrand(c.size())];

        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
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
