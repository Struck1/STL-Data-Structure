#pragma once
#include <iostream>

class myintarray
{

public:
    myintarray(int size)
    {
        std::cout << "ctor calisti" << size << std::endl;
        _size = size;
        _data = new int[size];
    }

    ~myintarray()
    {
        if (_data != nullptr)
        {
            delete[] _data;
        }
    }

    myintarray(const myintarray &other)
    {
        if (other._data == nullptr)
        {
            return;
        }

        _data = new int[other._size];
        _size = other._size;

        for (int i = 0; i < _size; i++)
        {
            _data[i] = other._data[i];
        }
    }

    myintarray &operator=(const myintarray &other1)
    {

        _size = 0;

        if (_data != nullptr)
        {
            delete[] _data;
        }

        if (other1._data == nullptr)
        {
            return *this;
        }

        _data = new int[other1._size];
        _size = other1._size;

        for (int i = 0; i < _size; i++)
        {
            _data[i] = other1._data[i];
        }

        return *this; //bu nesneyi return ettik
    }

    myintarray(myintarray &&other) //move constructor
    {
        _size = other._size;
        _data = other._data;

        other._size = 0;
        other._data = nullptr; // taşıdıkdan sonra taşınan nesneyi siliyoruz
    }

    myintarray &operator=(myintarray &&other) // move assignment operator
    {
        //öncelikle nesle oluşturulduğu için değerleri sıfırlayıp ardından istediğimiz nesneyi taşıyoruz.
        //taşıdıktan sonra taşınan nesneyi siliyoruz

        if (_data != nullptr)
        {
            delete[] _data;
        }

        _data = other._data;
        _size = other._size;

        other._size = 0;
        other._data = nullptr;

        return *this;
    }

    int &operator[](int index)
    {
        std::cout << "index " << index << std::endl;
        return _data[index];
    }

    void printaddres()
    {
        std::cout << _data << '\n';
        // std::cout << "burda" << '\n';
    }

private:
    int _size = 0;
    int *_data = nullptr;
};