#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string & i, const string & j)
{
    return i < j;
}

void read(istream & is, vector<string> & word)
{
    string temp;
    while (is >> temp)
        word.push_back(temp);
}

int main()
{
    vector<string> word;

    read(cin, word);

    sort(word.begin(), word.end(), compare);

    typedef vector<string>::size_type vec_sz;
    for(vec_sz i = 0; i != word.size(); )
    {
        cout << word[i];

        vec_sz n = 0;
        for (vec_sz j = i; j != word.size() && word[j] == word[i]; ++j)
        {
            ++n;
        }

        i += n;
        cout << setw(4) << n << endl;
    }

    return 0;
}
