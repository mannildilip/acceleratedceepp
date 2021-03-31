#ifndef _STUDENT_INFO_H
#define _STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>
#include <string>

struct Student_info
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};


std::istream& read_hw(std::istream& , std::vector<double>& );
std::istream& read(std::istream& , Student_info&);
bool compare(const Student_info& , const Student_info& );

#endif
