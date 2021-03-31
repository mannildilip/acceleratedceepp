#include <cctype>
#include <string>
#include <vector>

using std::vector;
using std::string;


vector<string> split(const string & s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while(i != s.size())
    {
        /* Ignore leading blanks
         * invariant: characters in range [original i, current i] are all spaces
         */
        while(i != s.size() && isspace(s[i]))
                ++i;

        /* Find end of next word */
        string_size j= i;
        while(j != s.size() && !isspace(s[j]))
            ++j;
        
        /* If we found some nonwhitespace characters, index j will move forward
         * */
        if(i != j)
        {
            /* Copy from s starting at i and taking j-i chars */
            ret.push_back(s.substr(i, j-i));
            i = j;

        }
    }
    return ret;

}
