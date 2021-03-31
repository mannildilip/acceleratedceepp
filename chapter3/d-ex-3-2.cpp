/* Program to calculate quartiles */
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

    /* Enter the list of numbers */
    cout << "Enter list of numbers followed by en-of-file: ";

    /* Variable to store the read value */
    vector<double> inp_numbers;
    double x;

    while (cin >> x)
    {
        inp_numbers.push_back(x);
    }

    /* Check whether some numbers are entered */
    typedef vector<double>::size_type vec_sz;
    vec_sz size = inp_numbers.size();

    if(size == 0)
    {   
        cout << endl << "You must enter some numbers, Pls Try again " << endl;
        return 1;
    }
    else if(size ==1)
    {
        cout << "Only 1 number supplied. Q1, Q2 and Q3 all equate to " << inp_numbers[0] << endl;
        return 1;
    }

    

    /* Sort the grades */
    sort(inp_numbers.begin(), inp_numbers.end());
    
    /* Identification of datum distribution profile
     * [0 0 0], [0 1 0], [1 0 1], [1 1 1]
     * This means whether data can be taken directly or
     * need to be averaged with neighbour */
    vec_sz mod4 = size % 4;
    string datumDist = "";
    vec_sz iM, iML, iMU;
    double mid, low, high;

    if(mod4 == 0)
    {
        datumDist = "[0 0 0]";
        iM = size/2;
        iML = iM/2;
        iMU = iM+iML;

        /* Calculate Quartile values */
        mid = (inp_numbers[iM] + inp_numbers[iM-1])/2;
        low = (inp_numbers[iML] +inp_numbers[iML-1])/2;
        high = (inp_numbers[iMU] + inp_numbers[iMU-1])/2;

    }
    else if(mod4 == 1)
    {
        datumDist = "[0 1 0]";
        iM = size/2;
        iML = iM/2;
        iMU = iM+iML+1;

        /* Calculate quartile values */
        low = (inp_numbers[iML] + inp_numbers[iML-1])/2;
        mid = inp_numbers[iM];
        high = (inp_numbers[iMU] + inp_numbers[iMU-1])/2;

    }

    else if(mod4 == 2)
    {
        datumDist = "[1 0 1]";
        iM = size/2;
        iML = iM/2;
        iMU = iM + iML;

        low = inp_numbers[iML];
        mid = (inp_numbers[iM] + inp_numbers[iM -1]) /2;
        high = inp_numbers[iMU];
    }
    else if(mod4 == 3)
    {
        datumDist = "[1 1 1]";
        iM = size/2;
        iML = iM/2;
        iMU = iM+iML+1;

        low = inp_numbers[iML];
        mid = inp_numbers[iM];
        high = inp_numbers[iMU];
    }

    else
    {
        cout << "Unknown pattern" << endl;
    }

    streamsize prec = cout.precision();
    cout << "Display the sorted (non-descending) vector below." << endl;
    cout << "Index: Number" << endl;
    for (vec_sz i = 0; i !=  size; ++i)
    {
        cout << i << ": " << inp_numbers[i] << endl;
    }
    cout << endl;
    cout << "Vector size: " << size << endl;
    cout << "Datum Distribution: " << datumDist << endl;
    cout << setprecision(3) << endl
         << " Q1: " << low << endl
         << " Q2: " << mid << endl
         << " Q3: " << high << endl
         << setprecision(prec);
    return 0;

}


