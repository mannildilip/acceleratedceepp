/* This program is the wrapper main for list example using iterators
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
#include <list>
#include <stdexcept>
#include "grade.h"
#include "student_info.h"

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;
using std::sort;    using std::list;
using std::domain_error;
using std::istream;
using std::ostream;
using std::max;
list<Student_info> extract_fails(list<Student_info>& students);

int main()
{
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    /* Read and store all the records, and find the length of longest name */
    while(read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    list<Student_info> fails = extract_fails(students);
    list<Student_info>::iterator i;

    for ( i = fails.begin(); i != fails.end(); ++i)
      cout << i->name << " " << grade(*i) << endl;

    return 0;
}
