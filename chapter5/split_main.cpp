#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> split(const string & s);

int main()
{
    string s;

    /* Read and split each line of input */
    while(getline(cin, s))
    {
        vector<string> v = split(s);

        /*write each word in v */
        for(vector<string>::size_type i=0; i != v.size(); i++)
            cout << v[i] << endl;
    }
    return 0;
}
