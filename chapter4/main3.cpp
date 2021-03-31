/* This program is just main2.c with functions and data structures moved to
 * appropriate files
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


int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    cout << "Enter grades in following format" << endl;
    cout << "Name midterm final and one or more hw assignment grades" << endl;

    /* Read and store all the records, and find the length of longest name */
    while(read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    /* Alphabetize the records */
    sort(students.begin(), students.end(), compare);

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
    return 0;
}
