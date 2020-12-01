#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

/*
Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, list has slow traversal,
but once a position has been found, insertion and deletion are quick.
Normally, when we say a List, we talk about doubly linked list. For implementing a singly linked list, we use forward list.
*/


template <typename T>
void print(T &t)
{
    typename T::iterator i = t.begin();
    while (i != t.end())
    {
        cout << *i++ << " ";
    }
    cout << std::endl;
}

int main()
{

    //constructors
    list<int> list1;
    list<int> list2(5, 9);
    list<int> list3(10);
    list<int> list4(list3.begin(), list3.end());

    print(list1);
    print(list2);
    print(list3);
    print(list4);

    cout << list1.empty() << endl;
    cout << list2.front() << endl;

    //add
    list3.insert(list3.end(), 7);
    print(list3);
    list3.push_back(99);
    list3.push_front(88);
    print(list3);

    cout << list3.size() << endl;

    //delete
    list3.remove(0);
    print(list3);

    //merge, sort
    list<int> list5;
    list5.push_back(78);
    list5.push_back(66);
    list5.push_back(1);
    /*
    list5.sort();
    list3.sort();
    */
    list3.merge(list5);

    print(list3);
    print(list5);
}