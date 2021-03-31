
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;

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

    int count = 0;
    double sum = 0;

    /* Variable to store the read value */
    double x;

    while (cin >> x)
    {
        //++count;
        count++;
        sum +=x;
    }
    cout << "count is :"<<count;
    /* output result */
    streamsize prec = cout.precision();
    cout << "Your final grade is" << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum/count
         << setprecision(prec) << endl;

    return 0;

}


