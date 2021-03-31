#include <algorithm>
#include <vector>

#include "../chapter5/student_info.h"
#include "grade.h"

using std::stable_partition;
using std::vector;

vector<Student_info>
extract_fails(vector<Student_info>& students)
{
    /* Move pass grades to starting of the vector */
    vector<Student_info>::iterator iter = stable_partition(students.begin(), 
            students.end(), pgrade);

    /* construct fail vector by taking iterator to end of pass and till end */
    vector<Student_info> fail(iter, students.end());

    /* erase fail grades from original student vector */
    students.erase(iter, students.end());

    return fail;
}
