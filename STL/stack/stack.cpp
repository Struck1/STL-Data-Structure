#include <iostream>
#include <stack>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::stack;
/*
Stacks are a type of container adaptors with LIFO(Last In First Out) type of working,
where a new element is added at one end and (top) an element is removed from that end only.
*/
template <typename T>
void print(stack<T> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    cout << s.empty() << endl;
    s.push(99);
    s.push(88);
    s.push(100);
    //100 88 99
    cout << "stack top: " << s.top() << endl;
    s.pop();
    //88 99
    cout << "stack top: " << s.top() << endl;
    cout << "stack size: " << s.size() << endl;
    print(s);

    ///
    std::string str = "kek";
    stack<char> s3;
    queue<char> q3;

    for (int i = 0; i < str.length(); i++)
    {
        s3.push(str[i]);
        q3.push(str[i]);
    }

    bool palindrom = true;
    while (!s3.empty() & !q3.empty())
    {
        if (s3.top() != q3.front())
        {
            palindrom = false;
            break;
        }
        s3.pop();
        q3.pop();
    }

    if (palindrom)
    {
        cout << str << " Kelimesi palindromdur" << endl;
    }
    else
    {
        cout << str << " Kelimesi palindrom değildir" << endl;
    }

    print(s3);
}