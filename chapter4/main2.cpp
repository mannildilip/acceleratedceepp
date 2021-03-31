/* This program focus in organizing program using data
 * Following program implement accepting, calculating and printing grades for
 * multiple students. Calculate overall grade using medians. 
 *
 * Re-implementing grading program in chapter3 using functions
 * Written functions to calculate median, grade and read hw grades*/
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;
using std::sort;    using std::vector;
using std::domain_error;
using std::istream;
using std::ostream;
using std::max;
struct Student_info
{
    string name;
    double midterm, final;
    vector<double> homework;
};
/* Read homework grade from an input stream into a vector<double> */
istream& read_hw(istream& in, vector<double>& hw)
{
    if(in)
    {
        /* Get rid of previous contents */
        hw.clear();

        /* Read hw grades */
        double x;
        while(in >> x)
            hw.push_back(x);

        /* Clear the stream so that input will work for the next student */
        in.clear();
    }
    return in;
}

/* Function to read student info and grades */
istream& read(istream& is, Student_info &s)
{
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
}
/* Compute the median of vector<double>
 * Calling this function copies the entire vector
 * */
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if(size ==0)
    {
        throw domain_error("Median of empty vector");
    }
    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0? (vec[mid] + vec[mid-1])/2:vec[mid];
}

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


bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}


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
