#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    /*
vector<int> v;
const vector<int> cv;
auto it1 = v.begin(); // it1 has type vector<int>::iterator
auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
auto it3 = v.cbegin(); // it3 has type vector<int>::const_iterator
*/

    /*
    vector<int> v{1, 2, 3, 4, 5};
    auto mid = v.begin() + v.size() / 2;
    cout << *mid << endl;
    //ex1
    */

    /*
    //find the first negative element in ia;
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -5};
    int *beg = begin(ia);
    int *last = end(ia); // pointer one past the last element in ia
    while (beg != last && *beg >= 0)
    {
        ++beg;
    }
    cout << *beg << endl;

   // ex2
    */

    /*

    //   constexpr int new_sz() { return 42; }
    //   constexpr int foo = new_sz(); 

    constexpr size_t sz = 5;
    int arr[sz] = {1, 2, 3, 4, 5};
    int *p = arr;
    int *p2 = p + 4;

    cout << *p2;
    

    int ia[] = {0, 2, 4, 6, 8};
    int last = *(ia + 4);
    cout << last;
    
    //ex3
    */
}