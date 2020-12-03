#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/*
Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted,
with their storage being handled automatically by the container.
Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.
In vectors, data is inserted at the end.
*/

/*
void print(vector<int> &v)
{
    // iterator
    vector<int>::iterator i = v.begin();
    while (i != v.end())
    {
        cout << *i << " ";
        i++;
    }
}
*/
template <typename T>
void print(vector<T> &v)
{
    // iterator
    typename vector<T>::iterator i = v.begin();
    while (i != v.end())
    {
        cout << *i << " ";
        i++;
    }
    cout << std::endl;
}

int main()
{
    vector<int> v1;
    vector<int> v2(5, 10);
    vector<int> v3(8);
    vector<int> v4(&v2[5], &v2[8]);
    vector<int> v5(v2);

    vector<std::string> v6(5, std::string("emre"));

    print(v3);
    print(v2);
    print(v6);

    // Vector member functions
    vector<int> v7;
    //eleman ekleme
    v7.insert(v7.begin(), 5);
    v7.insert(v7.end(), 7);
    v7.push_back(99); // push_back direk vektörün sonuna ekler her hangi bir iteratör vermemize gerek yok
    print(v7);
    cout << v7.empty() << endl; // false
    cout << *v7.begin() << endl;
    cout << v7.front() << endl;

    //eleman silme
    v7.erase(v7.begin() + 2, v7.end());
    print(v7);

    cout << v7.size() << endl;
    cout << v7.capacity() << endl;

    vector<int> v8;
    for (int i = 0; i < 10; i++)
    {
        v8.push_back(i * 3);
    }
    print(v8);

    v7.insert(v7.begin(), &v8[0], &v8[5]);
    print(v7);
}