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

int main()
{
    Node<int> *n1 = new Node<int>(3); // bellekten bir node'luk yer ayrıldı
    cout << n1->data << endl;
    cout << "n1 address: " << n1 << endl;
    Node<int> *n2 = new Node<int>(5);
    n1->next = n2; //n1 nodu artık next parametresi ile aynı zamanda n2 nodunun adresini işaret ediyor
    cout << n2->data << endl;
    cout << "n2 address: " << n2 << endl;
    cout << "n1 next: " << n1->next << endl;
    Node<int> *n3 = new Node<int>(9);
    n2->next = n3;
    cout << n3->data << endl;
    cout << "n3 address: " << n3 << endl;
    cout << "n2 next : " << n2->next << endl;

    Node<int> *n4 = n1;
    while (n4 != NULL)
    {
        cout << "data : " << n4->data << endl;
        n4 = n4->next;
    }
}