/* Chapter focuses in organizing program and data. This program focus in
 * organizing program using functions
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

int main()
{
    /* Ask for and read student's name */
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    cout << "Hello" << name << "!" << endl;

    /* Enter midterm and final grades */
    cout << "Please enter your midterm and final grades: ";
    double midterm, final;
    cin >> midterm >> final;

    /* Enter homework grades */
    cout << "Enter all the homework grades, "" followed by EOF: ";

    vector<double> homework;

    /* Read homework grades */
    read_hw(cin, homework);

    /* Compute and generate the final grade */
    try{
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
            << final_grade << setprecision(prec) << endl;
    } catch(domain_error){
        cout << endl << "You must enter your grades Please try again " << endl;
        return 1;
    }

return 0;

}
