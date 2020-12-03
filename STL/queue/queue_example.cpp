#include <iostream>
#include <queue>

using namespace std;

class Musteri
{
    string ad;
    int adet;

public:
    Musteri(string ad, int adet) : ad(ad), adet(adet) {}
    friend ostream &operator<<(ostream &, Musteri &);
};

ostream &operator<<(ostream &o, Musteri &m)
{
    o << m.ad << " " << m.adet << " ürün almak istiyor.";
    return o;
}

class Market
{
    queue<Musteri *> kuyruk;

public:
    void urunSat()
    {
        if (kuyruk.empty())
            cout << "Urun almayı bekeyen musteri yok" << endl;
        else
        {

            Musteri m = *kuyruk.front();
            cout << m << " Urunu verildi" << endl;
            kuyruk.pop();
        }
    }

    void kuyrugaGir(Musteri *m)
    {
        cout << "address: " << m << endl;
        if (m)
        {
            kuyruk.push(m);
        }
    }

    friend ostream &operator<<(ostream &, Market &);
};

ostream &operator<<(ostream &o, Market &m)
{
    if (m.kuyruk.empty())
    {
        o << "Kuyrukta müsteri yok " << endl;
    }
    else
    {
        int i = 1;
        o << "Kuyrukta bekleyen müsteriler: " << endl;
        queue<Musteri *> kuyruk = m.kuyruk; //copy constr
        while (!kuyruk.empty())
        {
            Musteri m = *kuyruk.front();
            o << i << " - " << m << endl;
            kuyruk.pop();
            i++;
        }
        o << endl;
    }
    return o;
}

main()
{
    Market market;
    Musteri m("Emre", 3);
    Musteri m2("Ahmet", 4);
    Musteri m3("Ahmet", 8);
    Musteri m4("Ahmet", 7);
    Musteri m5("Falan", 7);
    //cout << m << endl;
    cout << "address m: " << &m << endl;
    market.kuyrugaGir(&m);
    market.kuyrugaGir(&m2);
    market.kuyrugaGir(&m3);
    market.kuyrugaGir(&m4);
    //market.urunSat();
    cout << market;
    market.urunSat();
    cout << market;
    market.urunSat();
    market.urunSat();
    market.kuyrugaGir(&m5);
    cout << market;
    market.urunSat();
    market.urunSat();
    market.urunSat();
    cout << market;
}

/*
// Friend 

class A
{
private:
    int x;

public:
    int getX();
    void setX(int);
    friend void Foo(A &);
};

int A::getX() { return x; }

void A::setX(int _x) { x = _x; }

void Foo(A &a) { a.x = 0; }

int main()
{
    A n;
    n.setX(8);
    cout << n.getX() << endl;
    Foo(n);
    cout << n.getX();
}


*/