#include <iostream>

using namespace std;

class Box
{
private:
    double length;
    double width;
    double height;

public:
    Box()
    {
        cout << "box constructor " << endl;
    }

    Box(double l, double w, double h)
    {
        length = l;
        width = w;
        height = h;

        if (w < 0)
        {
            cout << "width cannot be lowe than zero " << endl;
            width = 0.0;
        }

        cout << "box volume: " << this->length * this->width * this->height << endl;
    }

    ~Box()
    {
        cout << "box destructor" << endl;
    }

    double getVolume()
    {
        return length * width * height;
    }

    void setLength(double l)
    {
        if (l < 0)
        {
            cout << "l must be greater than zero" << endl;
        }
        else
        {
            length = l;
        }
    }

    void setWith(double w)
    {
        if (w < 0)
        {
            cout << "w must be greater than zero" << endl;
        }
        else
        {
            width = w;
        }
    }

    void setHeight(double h)
    {
        if (h < 0)
        {
            cout << "h must be greater than zero" << endl;
        }
        else
        {
            height = h;
        }
    }

    Box &operator=(const Box &r)
    {
        this->height = r.height;
        this->length = r.length;
        this->width = r.width;

        return *this;
    }

    bool operator==(const Box &r)
    {
        double thisVolume = (this->width * this->height * this->length);
        double referanceVolume = (r.length * r.height * r.width);

        if (thisVolume == referanceVolume)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<(const Box &r)
    {
        double thisVolume = (this->width * this->height * this->length);
        double referanceVolume = (r.length * r.height * r.width);

        if (thisVolume < referanceVolume)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>(const Box &r)
    {
        double thisVolume = (this->width * this->height * this->length);
        double referanceVolume = (r.length * r.height * r.width);

        if (thisVolume > referanceVolume)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Box operator+(const Box &r)
    {
        Box boxInt;
        boxInt.length = this->length + r.length;
        boxInt.width = this->width + r.width;
        boxInt.height = this->height + r.height;

        return boxInt;
    }

    void display() const
    {
        cout << "length/width/height" << endl;
        cout << " " << this->length << " " << this->width << " " << this->height << endl;
    }
};

int main()
{
    /*
    Box box;
    Box box2(20.0, 30.0, 10.0);
    cout << "box volume: " << box2.getVolume() << endl;
    box2.setLength(-21.0);
    cout << "box volume: " << box2.getVolume() << endl;
    box = box2;
    cout << box.getVolume() << endl;
    */

    Box box2(4, 3, 2);

    Box box3;
    box3 = box2;

    Box box4;

    box4 = box2 + box3;

    box2.display();
    box3.display();
    box4.display();

    if (box2 == box3)
    {
        cout << "equal" << endl;
    }
    else
    {
        cout << "not equal" << endl;
    }

    if (box4 > box3)
    {
        cout << "box4 grater than box3" << endl;
    }
    else
    {
        cout << "box4 smaller than box3" << endl;
    }

    return 0;
}