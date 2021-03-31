#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "student_info.h"

using std::domain_error; using std::vector;

/* Compute a student's overall grade from midtem, final and homework grades */
double grade(double midterm, double final, double homework)
{
    return 0.2*midterm + 0.4 * final + 0.4*homework;
}

/* Compute a student's overall grade from midterm, final exam grades and 
 * vector of homework grades
 * This function doesn't copy its arguments, because median() does so for us*/
double grade(double midterm, double final, const vector<double>& hw)
{
    if(hw.size() == 0)
    {
        throw domain_error("Student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

/* Predicate to determine whether a student failed */
bool fgrade(struct Student_info& s)
{
    return grade(s) < 60;
}


