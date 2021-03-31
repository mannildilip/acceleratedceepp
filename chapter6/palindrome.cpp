#include <string>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::equal;
using std::string;


/* Function return true if the passed string is a palindrome
 * It uses the library algorithm equal to perform this. 
 * First two arguments refer to iterators to original string and
 * 3rd argument defines the starting point iterator which is end of original
 * string */
bool is_palindrome(const string &s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
    string s;
    while(cin >> s)
    {
        if(is_palindrome(s))
            cout << s << " is a palindrome" << endl;
        else
            cout << s << " is not a palindrome" << endl;

    }
    return 0;
}
