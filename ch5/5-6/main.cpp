#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "student_info.h"

using namespace std;

bool fgrade(const Student_info & s)
{
    return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info> & students)
{
    vector<Student_info>::size_type count = 0;
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
    {
        if (!fgrade(students[i]))
            students[count++] = students[i];
    }

    students.resize(count);
    return students;
}

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

    extract_fails(students);

    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        cout << "pass students:\n";

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

    return 0;
}
