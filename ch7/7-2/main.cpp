#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "student_info.h"
#include <map>

using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;  //最长姓名的长度

    while (read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        //输出姓名
        cout << setw(maxlen + 1) << students[i].name << " ";

        //输出成绩
        try
        {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }

    cout << endl;

    map<string, int> counters;
    for(vector<Student_info>::const_iterator it = students.begin();
        it != students.end(); ++it)
    {
        double final_grade = grade(*it);
        if (final_grade >= 90 && final_grade <= 100)
            ++counters["90-100"];
        else if (final_grade >= 80)
            ++counters["80-89.99"];
        else if (final_grade >= 70)
            ++counters["70-79.99"];
        else if (final_grade >= 60)
            ++counters["60-69.99"];
        else
            ++counters["<60"];
    }

    for (map<string, int>::reverse_iterator it = counters.rbegin();
         it != counters.rend(); ++it)
    {
        if (it->first != "<60")
        {
            cout << it->first << "\t" << it->second << endl;
        }
    }

    map<string, int>::const_iterator it = counters.find("<60");
    if (it != counters.end())
        cout << it->first << "\t" << it->second << endl;

    return 0;
}
