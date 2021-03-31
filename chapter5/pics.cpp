#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::max;

string::size_type width(const vector<string>& v);
/* This function finds the sring with max width */
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen=0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}

/* Function frame the strings by taking max len string and aligning all further
 * strings to this 
**************
* this is an *
* example    *
* to         *
* illustrate *
* framing    *
**************
 * */
vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);

    /* Maxlen of string + extra 4 * for border and initial and trailing spaces */
    string border(maxlen + 4, '*');

    /* Write top border */
    ret.push_back(border);

    /* write each interior row, bordered by an asterisk and space */
    for(vector<string>::size_type i =0; i != v.size(); ++i)
    {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }


    /* write bottom boarder */
    ret.push_back(border);
    return ret;

}

/* Function to concatenate original input and framed input horizontally 
************** this is an
* this is an * example
* example    * to
* to         * illustrate
* illustrate * framing
* framing    * 
************** 
 * */
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    /*Add 1 to leave space between picture */
    string::size_type width1 = width(left) + 1;

    /* Indices to look at elements from left and right respectively */
    vector<string>::size_type i = 0, j = 0;


    while(i != left.size() || j != right.size())
    {
        /* construct new string to hold characters from both pictures */
        string s;

        /* copy a row from left-hand side, if there is one */
        if(i != left.size());
        s = left[i++];

        /* pad to full width */
        s += string(width1 - s.size(), ' ');

        /* copy a row from rhs, if there is one */
        if(j != right.size())
            s += right[j++];

        /* add s to the picture we are creating */
        ret.push_back(s);
    }
    return ret;
}

/* Function to concatenate original input and framed input vertically */
vector<string> vcat(const vector<string>& top,  const vector<string>& bottom)
{
    /*Copy the top pic */
    vector<string> ret = top;

    /* Copy entire bottom pic */
    for(vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
    {
        ret.push_back(*it);
    }
    return ret;
}
