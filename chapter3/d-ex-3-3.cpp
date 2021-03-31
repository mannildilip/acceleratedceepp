
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
    vector<string> words;
    vector<int> count;

    typedef vector<string>::size_type vec_size;

    cout << "Please enter words: ";
    string s;

    while(cin >> s)
    {
        bool found = false;
        for(vec_size i =0; i < words.size(); i++)
        {
            if(s == words[i])
            {
                count[i]++;
                found = true;
            }
        }
        if(!found)
        {
            words.push_back(s);
            count.push_back(1);
        }
    }
    for(vec_size i=0; i < words.size(); i++)
        cout << words[i] << "appeared " << count[i] << "times" << endl;
}


