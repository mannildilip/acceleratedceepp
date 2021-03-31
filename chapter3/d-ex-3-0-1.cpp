/* Use median for homework scores  */
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;
using std::sort;    using std::vector;

int main()
{
    /* Query student's name */
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello" << name << "!" << endl;

    /* Enter midterm and final grades */
    cout << "Please enter your midterm and final grades:  ";
    double midterm, final;
    cin >> midterm >> final;

    /* Enter homework grades */
    cout << "Enter all your homework grade followed by en-of-file: ";

    //int count = 0;
    //double sum = 0;

    /* Variable to store the read value */
    vector<double> homework;
    double x;

    while (cin >> x)
    {
        //++count;
        //count++;
        //sum +=x;
        homework.push_back(x);
    }

    /* Check whether some homework grades are entered */
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if(size == 0)
    {   
        cout << endl << "You must enter your grades Pls Try again " << endl;
        return 1;
    }

    /* Sort the grades */
    sort(homework.begin(), homework.end());

    /* Compute the median hw grade */
    vec_sz mid = size/2;
    double median;

    median = size % 2 == 0 ? (homework[mid] + homework[mid-1])/2:
                                homework[mid];



    /* output result */
    streamsize prec = cout.precision();
    cout << "Your final grade is" << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;

    return 0;

}


