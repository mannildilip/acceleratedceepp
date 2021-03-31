#include <list>
#include "student_info.h"
#include "grade.h"

using std::list;

/* This program is similar to erase_pf_vec_iter. The only difference is the use of 
 * list instead of vector. It provides better performance due to faster random
 * access performance of lists
 *  */
list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    
    while(iter != students.end())
    {
        if(fgrade(*iter))
        {
            fail.push_back(*iter);
            iter=students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}
