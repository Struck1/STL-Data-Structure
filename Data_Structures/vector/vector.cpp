#include <iostream>

using namespace std;

template <class T>
class vector_
{
    T *data;
    int cap;
    int index;
    void growth()
    {
        if (size() >= capacity())
        {
            cap *= 2;
            T *tmp = new T[cap];
            for (int i = 0; i < size(); i++)
                tmp[i] = data[i];

            delete[] data;
            data = tmp;
        }
    }

    void shrink()
    {
        if (size() < capacity() / 2)
        {
            cap /= 2;
            T *tmp = new T[cap];
            for (int i = 0; i < size(); i++)
                tmp[i] = data[i];

            delete[] data;
            data = tmp;
        }
    }

    void reset(int index = 0, int cap = 1)
    {
        delete[] data;
        data = NULL;
        this->index = index;
        this->cap = cap;
    }

public:
    vector_() : data(NULL), index(0), cap(1)
    {
        data = new T[cap]; //address
    }

    int size() const { return index; }
    int capacity() const { return cap; }

    void push_back(const T &value)
    {
        growth();
        data[index++] = value;
    }
    void pop_back()
    {
        if (isEmpty())
        {
            throw "Error vector is empty";
        }
        index--;
        shrink();
    }

    bool isEmpty() const { return size() == 0; }

    T front() const
    {
        if (isEmpty())
        {
            throw "Error vector is empty";
        }
        return data[0];
    }

    T back() const
    {
        if (isEmpty())
        {
            throw "Error vector is empty";
        }
        return data[index - 1];
    }

    T *begin() const
    {
        return data;
    }

    T *end() const
    {
        return data + size();
    }

    T &at(int indis)
    {
        if (indis >= 0 && indis < size())
            return data[indis];
        throw "Error: overflow";
    }

    T &operator[](int indis)
    {
        return at(indis);
    }

    void clear()
    {
        reset();
        data = new T[cap];
    }

    void print()
    {

        T *first = begin();
        T *last = end();
        while (first != last)
        {
            cout << *first << " ";
            first++;
        }
        cout << endl;
    }
};

int main()
{
    vector_<int> v;
    try
    {
        cout << "capacity: " << v.capacity() << endl;
        cout << "size: " << v.size() << endl;
        cout << "isEmpty: " << v.isEmpty() << endl;
        v.push_back(88);
        cout << "front: " << v.front() << endl;
        // v.pop_back();
        cout << "front: " << v.front() << endl;

        v.push_back(89);
        v.push_back(90);
        cout << "back: " << v.back() << endl;
        cout << "capacity: " << v.capacity() << endl;
        cout << "size: " << v.size() << endl;
        /*
        v.pop_back();
        v.pop_back();
        cout << "back: " << v.back() << endl;
        cout << "capacity: " << v.capacity() << endl;
        cout << "size: " << v.size() << endl;
        */
        cout << "begin: " << v.begin() << endl;
        cout << "end: " << v.end() << endl;

        /*
        int *begin = v.begin();
        int *end = v.end();
        while (begin != end)
        {
            cout << *begin << " ";
            begin++;
        }
        */
        v.print();
        cout << v[0] << endl;
        v[2] = 50;
        v.print();
        v.clear();
        v.print();
    }
    catch (const char *exception)
    {
        cout << exception;
    }
}