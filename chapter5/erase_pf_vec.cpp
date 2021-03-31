#include <vector>
#include "student_info.h"
#include "grade.h"

using std::vector;

/* Instead of having pass/fail vector allocated, return fail and erase failed
 * students from the original student vector passed
 * This is potentially slow due to vector behavior
 *  */
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;
    
    while(i != students.size())
    {
        if(fgrade(students[i]))
        {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }
        else
            ++i;
    }
    return fail;
}
