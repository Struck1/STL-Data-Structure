#include <iostream>
#include <exception>

using namespace std;

class Myexcepton : public exception
{
public:
    virtual const char *what() const throw()
    {

        return "my exception";
    }
};

class A
{
public:
    void getThrow()
    {
        throw Myexcepton();
    }
};

using namespace std;

int main()
{
    A a;
    try
    {
        a.getThrow();
    }
    catch (Myexcepton &e)
    {
        cout << e.what() << endl;
    }
}