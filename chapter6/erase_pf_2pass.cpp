#include <algorithm>
#include <iterator>
#include <vector>

#include "../chapter5/student_info.h"
#include "grade.h"

using std::back_inserter;
using std::remove_copy_if;
using std::remove_if;
using std::vector;

/* The function separate sudent record to pass and fail record. Function return
 * failed records. Pass records are created organized in reference passed */
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;

    /* Function to copy fail grades to fail vector */
    remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);

    /* Modify the original reference passed to remove the fail grades. remove_if
     * reorder the students vector by moving pass grades to front and returns
     * iterator to end of pass grades. erase() remove from this iterator to end*/
    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

    return fail;
}
