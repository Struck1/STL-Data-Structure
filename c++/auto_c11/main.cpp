#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    /*
    string s("hello word");

    for (auto &c : s) // for every char in s (c is a referance)
    {
        c = toupper(c);
    }
    cout << s << endl;

    //ex1
    */

    /*
    vector<int> v{1, 2, 3, 4, 5};

    for (auto &i : v)
        i *= i;

    for (auto i : v)
        cout << i << " ";

    //ex2
    */

    /*
    string str("some string");
    if (str.begin() != str.end())
    {
        auto it = str.begin();
        *it = toupper(*it);
    }

    cout << str << endl;

    for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
        *it = toupper(*it);

    cout << str << endl;

    //ex3
    */
}