/* This program builds on top of grading program written in ch 4 & 5. There is a
 * flaw in grade calculation programs in previous chapter. If a student didn't
 * submit hw assignments, he is not penalized because median is being calculated
 * This is a flaw which is handled in this program in multiple ways
 * 1. Calculate average by taking mark of hw not submitted as zero
 * 2. Calculate optimistic median, by assuming grade of the hw not submitted is
 * same as what is submitted
 * 3. Calculate median where taking marks for non submitted assignments as 0
 * pessimist median ;)
 *
 * Will reuse student_info and median code written in chapter 5
 * */
#include <vector>
#include <iostream>
#include <algorithm>
#include "analysis.h"
#include "../chapter5/student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

using std::find;
bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0))
		 == s.homework.end());
}


int main()
{
    /* Students who did and didn't do all the homework */
    vector<Student_info> did, didnt;

    /* Read the student records and partition them */
    Student_info student;

    while(read(cin, student))
    {
        if(did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    /* Check whether student record did and didnt have some data */
    if(did.empty())
    {
        cout << "No student did all homework!" << endl;
        return 1;
    }
    if(didnt.empty())
    {
        cout << "Every student did homework!" << endl;
        return 1;
    }

    /* Do the analysis */
    /* Takes median(pessimistic) of hw grades */
    write_analysis(cout, "median", median_analysis, did, didnt);
    /* Takes average of hw grades */
    write_analysis(cout, "average", median_analysis, did, didnt);
    /* Takes optimistic median of hw grades */
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis,
                        did, didnt);


    return 0; 
}


