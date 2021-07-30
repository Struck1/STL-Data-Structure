#include <iostream>
#include <string>

using namespace std;

void errorfunc()
{
    bool error1 = true;
    bool error2 = true;

    if (error1)
    {
        //throw 8;
        throw "something went wrong";
    }

    if (error2)
    {
        //throw 8;
        throw string("something else went wrong");
    }
}

int main()
{
    try
    {
        errorfunc();
    }
    catch (int e)
    {
        cout << "error message: " << e << endl;
    }
    catch (char const *e)
    {
        cout << "error message: " << e << endl;
    }
    catch (string &e)
    {
        cout << "string error message : " << e << endl;
    }

    return 0;
}