#include <iostream>
#include "myintarray.h"

myintarray make_array(int size) //rvalue döner çünkü return edilen değerin referansını alamıyoruz
{
    myintarray a(size);

    return a;
}

int main()
{
    myintarray a1(5); //copy ctor

    a1[0] = 8;

    myintarray a2(6); //copy ctor

    myintarray a3 = a1; //copy ctor

    myintarray a4(6);
    a4 = a1; // copy assignment operator

    myintarray a5(std::move(a2)); //move ctor myintarray a5 = std::move(a2);
    myintarray a6(6);
    a6 = std::move(a1); // move assignment operator;

    a6 = make_array(15); //rvalue dönüş tipi olduğu için rvalue referance parametresi alan(&&) fonksiyon çağrılır
                         //a6 önceden tanımlandığı için move assignment operator çağrılır.

    myintarray a7 = make_array(5); //rvalue dönüş tipi olduğu için rvalue referance parametresi alan(&&) fonksiyon çağrılır
                                   //a7 yeni oluşturulmakta olduğu için move ctor çağrılır

    a2.printaddres(); // 0
    a4.printaddres();
    a5.printaddres();
    a6.printaddres();
    return 0;
}