#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Node
{
public:
    Node(const T &data = T(), Node<T> *next = NULL) : data(data), next(next) {}
    T data;
    Node<T> *next;
};

class list
{
    Node<int> *root;

public:
    list() : root(NULL) {}
    Node<int> *begin() const { return root; }
    Node<int> *end() const { return NULL; }
    //bool isEmpty() const { return root == NULL; }
    bool isEmpty() const { return begin() == end(); }
    void push_back(const Node<int> &value)
    {
        if (isEmpty())
        {
            root = new Node<int>(value);
            cout << "adress root: " << root << " " << root->data << " " << root->next << endl;
        }
        else
        {

            cout << begin() << endl;
            Node<int> *tmp = begin();

            while (tmp->next != end())
            {
                tmp = tmp->next;
            }
            tmp->next = new Node<int>(value);
            cout << "new push_back : " << tmp << " data: " << tmp->next->data << " next: " << tmp->next << endl;
        }
    }

    void push_front(const Node<int> &value)
    {
        Node<int> *tmp = new Node<int>(value);
        tmp->next = root;
        root = tmp;
    }

    int front() const
    {
        if (isEmpty())
            throw "Error: list::front() list is empty";
        return begin()->data;
    }

    int back() const
    {
        if (isEmpty())
            throw "Error: list::back() list is empty";

        Node<int> *tmp = begin();
        while (tmp->next != end())
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }

    void pop_back()
    {
        if (isEmpty())
            throw "Error : List::pop_back() list is empty";
        if (begin()->next == end())
        {
            delete root;
            root = NULL;
        }
        else
        {
            Node<int> *tmp = begin();
            while (tmp->next->next != end())
                tmp = tmp->next;
            delete tmp->next;
            tmp->next = NULL;
        }
    }

    void print()
    {
        Node<int> *tmp = begin();
        while (tmp != end())
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{
    list l;
    cout << l.isEmpty() << endl;
    l.push_back(5);
    l.push_back(99);
    l.push_back(88);
    cout << l.isEmpty() << endl;
    l.print();
    l.push_back(77);
    l.print();
    l.push_front(777);
    l.print();
    cout << "list back: " << l.back() << endl;
    cout << "list front: " << l.front() << endl;
    l.pop_back();
    l.print();
    l.push_back(999);
    l.print();
    /*
    Node<int> *first = l.begin();
    Node<int> *last = l.end();

    while (first != last)
    {
        cout << first->data << " ";
        first = first->next;
    }
    */
}