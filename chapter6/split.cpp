#include <cctype>
#include <algorithm>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::find_if;


/*True if argument is white space, false otherwise */
bool space(char c)
{
    return isspace(c);
}

/* False if the argument is whitespace, true otherwise */
bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();

    while(i != str.end())
    {
        /*ignore leading blanks - after this i is pointing to non space char */
        i = find_if(i, str.end(), not_space);

        /*Find end of word */
        iter j = find_if(i, str.end(), space);

        /* Copy characters between i and j */
        if(i != str.end())
            ret.push_back(string(i, j));

        /* skip and start from next word */
        i = j;

    }
    return ret;
}
