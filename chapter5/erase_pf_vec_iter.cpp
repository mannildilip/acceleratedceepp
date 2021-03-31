#include <vector>
#include "student_info.h"
#include "grade.h"

using std::vector;

/* This program is similar to erase_pf_vec. The only difference is the use of 
 * iterators instead of indexing. It provides a standard way of moving
 * across container objects. Indexing will not work for all containers, for eg:-
 * list
 *  */
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    
    while(iter != students.end())
    {
        if(fgrade(*iter))
        {
            fail.push_back(*iter);
            students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}
