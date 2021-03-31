#include <algorithm>
#include <string>
#include <vector>

using std::find;
using std::find_if;
using std::search;
using std::string;
using std::vector;
bool not_url_char(char c);

/* Function returns the end of url string */
string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

/* Function that return 0 if non url character is found, else 1 */
bool not_url_char(char c)
{
    /*characters, in addition to alphanumerics, that can appear in a \s-1URL\s0
     * */
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	/* see whether `c' can appear in a \s-1URL\s0 and return the negative */
	return !(isalnum(c) ||
	         find(url_ch.begin(), url_ch.end(), c) != url_ch.end());

}

/* This function return iterator to the beginning of an url. The function is
 * messy because input might contain :// which is not actually part of URL */
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";

    typedef string::const_iterator iter;

    iter i = b;

    while((i = search(i, e, sep.begin(), sep.end())) != e)
    {
        /* Make sure separator isn't at the beginning or at end of the line   */
        if(i !=b && i + sep.size() != e)
        {
            /* beg marks the beginning of protocol name */
            iter beg = i;
            while(beg != b && isalpha(beg[-1]))
                --beg;
            /* Is there one appropriate character before and after the separator */
            if(beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        /* the separator fund wasn't part of URL; advance i past this separator */
        i += sep.size();
    }
    return e;
}


vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    /* Look through entire input */
    while(b != e)
    {
        /* Look for one or more letters followed by :// */
        b = url_beg(b, e);

        /* If found, find end of url and copy entire url */
        if(b != e)
        {
            iter after = url_end(b, after);

            /* Store the url */
            ret.push_back(string(b, after));

            /* Reinitialize b to the end of currently found url to continue the process */
            b = after;
        }
    }
    return ret;
}
