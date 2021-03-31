/* This program is the wrapper main for 4 examples using vectors, lists and
 * iterators. It will be linked with one different file for each example to
 * create corresponding executable.
 *
 * This code is used as wrapper for 2 programs in chapter 6 also that uses
 * algorithm to solve same problem rather than writing loops ans iterators 
 *
 * median.cpp/h - Remains same as what is implemented in chapter04
 * student_info.cpp/h - Remains same as what is implemented in chapter04
 * grade.cpp/h - Minor update. Added predicate to determine whether student
 * failed
 */
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "grade.h"
#include "student_info.h"

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;
using std::sort;    using std::vector;
using std::domain_error;
using std::istream;
using std::ostream;
using std::max;
vector<Student_info> extract_fails(vector<Student_info>& students);


int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    /* Read and store all the records, and find the length of longest name */
    while(read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    /* Alphabetize the records */
    sort(students.begin(), students.end(), compare);

    vector<Student_info> fails = extract_fails(students);

    for (int i = 0; i < fails.size(); ++i)
        cout << fails[i].name << " " << grade(fails[i]) << endl;
#if 0
    for(vector<Student_info>::size_type i=0; i != students.size(); ++i)
    {
        /* write the name, padded on the right to maxlen+1 characters */
        cout << students[i].name << string(maxlen +1 - students[i].name.size(), ' ');

        /* Compute and write grade */
        try
        {
            double final_grade =  grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch(domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }
#endif
    return 0;
}
