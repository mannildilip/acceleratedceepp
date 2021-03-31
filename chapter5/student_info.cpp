#include "student_info.h"

using std::istream; using std::vector;

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

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}


