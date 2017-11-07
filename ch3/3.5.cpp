#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    typedef vector<string>::size_type vec_sz;
    cout << "Enter student name: ";

    string name;
    const int grade_num = 5;

    vector<int> grade;
    vector<string> names;
    while (cin >> name)
    {
        names.push_back(name);

        cout << "Enter " << grade_num << " grades: ";

        int x;
        int sum = 0;
        for (int i = 0; i < grade_num; ++i)
        {
            cin >> x;
            sum += x;
        }

        grade.push_back(sum);

        cout << "Enter next student name or end-of-file to exit: ";
    }

    cout << endl;
    cout << "Each student grade:\n";
    for (vec_sz i = 0; i < names.size(); ++i)
    {
        cout << "student: " << names[i] << endl;
        cout << "grade: " << grade[i] << endl << endl;
    }

    return 0;
}
