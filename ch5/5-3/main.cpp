#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include "grade.h"
#include "student_info.h"
#include <list>

using namespace std;

bool fgrade(const Student_info & s)
{
    return grade(s) < 60;
}

list<Student_info> extract_fails(list<Student_info> & students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}

int main()
{
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;  //最长姓名的长度

    while (read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    students.sort(compare);

    list<Student_info> fail_students = extract_fails(students);

    for (list<Student_info>::iterator iter = students.begin();
         iter != students.end(); ++iter)
    {
        cout << "pass students:\n";

        //输出姓名
        cout << setw(maxlen + 1) << (*iter).name << " ";

        //输出成绩
        try
        {
            double final_grade = grade(*iter);
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

    for (list<Student_info>::iterator iter = fail_students.begin();
         iter != fail_students.end(); ++iter)
    {
        cout << "fail students:\n";

        //输出姓名
        cout << setw(maxlen + 1) << (*iter).name << " ";

        //输出成绩
        try
        {
            double final_grade = grade(*iter);
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
