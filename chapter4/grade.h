#ifndef _GRADE_H_
#define _GRADE_H_

#include <vector>
#include "student_info.h"

double grade(double midterm, double final, double homework);

double grade(double midterm, double final, const std::vector<double>& hw);

double grade(const Student_info& s);

#endif
