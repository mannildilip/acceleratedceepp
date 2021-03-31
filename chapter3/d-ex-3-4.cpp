/* Program to report the length of longest and shortest sting in input */
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;

int main()
{
    typedef string::size_type str_size;

    string shortest;
    string longest;

    str_size long_len = 0;
    str_size short_len = 0;


    cout << "Please enter words: ";
    string s;

    while(cin >> s)
    {
        if(long_len == 0 || s.size() > long_len)
        {
            longest = s;
            long_len = s.size();
        }
        if(short_len == 0 || s.size() < short_len)
        {
            shortest = s;
            short_len = s.size();
        }
    }

    cout << "Longest: " << longest << endl;
    cout << "Shortest: " << shortest << endl;
}


