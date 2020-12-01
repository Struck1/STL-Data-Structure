#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

/*
Queues are a type of container adaptors which operate in a first in first out (FIFO) type of arrangement.
Elements are inserted at the back (end) and are deleted from the front.
*/

template <typename T>
void print(queue<T> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;

    cout << q.empty() << endl;
    q.push(88);
    q.push(1);
    q.push(3);
    //5 1 3
    cout << q.empty() << endl;
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    cout << "size: " << q.size() << endl;

    q.pop();
    //1 3
    cout << "front: " << q.front() << endl;
    cout << "size: " << q.size() << endl;

    //copy constructure
    queue<int> q1(q);
    cout << "q1 front: " << q1.front() << endl;
    q1.pop();
    cout << "q1 size: " << q1.size() << endl;
    cout << "q size: " << q.size() << endl;

    print(q);
    print(q1);
}
