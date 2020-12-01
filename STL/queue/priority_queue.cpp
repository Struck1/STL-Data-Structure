#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::priority_queue;
using std::queue;

/*
Priority queues are a type of container adapters, specifically designed such that the first element
of the queue is the greatest of all elements in the queue and elements are in non increasing
order (hence we can see that each element of the queue has a priority {fixed order})
*/

/*
 5 -> 5
 8 -> 5 < 8 = 8 5
 2 -> 2 < 8 
      2 < 5 =8 5 2
20 -> 8 < 20 = 20 8 5 2

*/
template <typename T>

void print(T p)
{
    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    priority_queue<int> p;
    cout << p.empty() << endl;
    p.push(5);
    print(p);
    p.push(8);
    print(p);
    p.push(2);
    print(p);
    p.push(20);
    print(p);
    cout << "p top: " << p.top() << endl;

    //greater
    priority_queue<int, std::vector<int>, std::greater<int>> p2;

    for (int i : {1, 8, 9, 22, 88, 22, 2})
    {
        p2.push(i);
    }

    print(p2);

    //example
    std::vector<int> vec;
    int random;
    for (int i = 0; i < 10; i++)
    {
        random = (rand() % 100);
        cout << random << " ";
        vec.push_back(random);
    }

    priority_queue<int> p3(vec.begin(), vec.end());
    cout << endl;

    print(p3);
}