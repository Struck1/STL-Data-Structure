#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/*
Double ended queues are sequence containers with the feature of expansion and contraction on both the ends.
*/

template <typename T>
void print(T &d)
{

    typename T::iterator iter = d.begin();
    while (iter != d.end())
    {
        cout << *iter++ << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> d;
    cout << "empty: " << d.empty() << endl;

    d.push_back(2);
    d.push_back(30);
    d.push_front(88);
    cout << "deque front: " << d.front() << endl;
    cout << "deque back: " << d.back() << endl;
    cout << "push_back / front " << endl;
    print(d);

    cout << "pop_back/front" << endl;
    d.pop_back();
    print(d);
    d.pop_front();
    print(d);

    cout << "insert" << endl;
    d.insert(d.begin(), 77);
    print(d);

    vector<int> v;
    v.push_back(999);
    v.push_back(777);
    cout << "Vector: " << endl;
    print(v);
    //insert
    cout << "insert" << endl;
    d.insert(d.begin(), &v[0], &v[2]);
    print(d);

    cout << "erase" << endl;
    // d.erase(d.begin());
    //print(d);
    d.erase(d.begin() + 1);
    print(d);

    cout << "size: " << endl;
    cout << d.size() << endl;
    d.resize(10, 9);
    print(d);

    deque<int> d2(d);
    print(d2);

    deque<int> d3(&d2[1], &d2[7]);
    print(d3);
}
