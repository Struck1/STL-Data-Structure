#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Insan
{
protected:
    string isim;
    int yas;
    bool durum;

public:
    Insan(string isim, int yas, bool durum = false) : isim(isim), yas(yas), durum(durum) {}
    void print() const
    {
        cout << "İsim: " << isim << endl
             << "Yas: " << yas << endl
             << "Durum: ";
        if (durum)
        {
            cout << "Evet";
        }
        else
        {
            cout << "Hayır";
        }
        cout << endl;
    }
};

class Hasta : public Insan
{
    int hastaNo;
    int oncelikPuani;

public:
    Hasta(int hastaNo, Insan &i) : hastaNo(hastaNo), Insan(i), oncelikPuani(0) { oncelikPuaniHesapla(); }
    Hasta(int hastaNo, string isim, int yas, bool engel = false) : hastaNo(hastaNo), Insan(isim, yas, durum), oncelikPuani(0) { oncelikPuaniHesapla(); }
    void oncelikPuaniHesapla()
    {
        if (durum)
        {
            oncelikPuani += 30;
        }
        if (yas > 65)
        {
            oncelikPuani += yas - 65;
        }
    }
    void on()
    {
        cout << oncelikPuani;
    }

    bool operator<(const Hasta &h) const
    {
        return oncelikPuani < h.oncelikPuani;
    }

    void print() const
    {
        cout << "Hasta No: " << hastaNo << endl;
        Insan::print();
        cout << "Oncelik puanı: " << oncelikPuani << endl;
    }
};

class HastaKayit
{
    list<Hasta> kayitSirasi;
    priority_queue<Hasta> muayeneSirasi;

public:
    void kayit(Insan &i)
    {
        Hasta hasta(kayitSirasi.size() + 1, i);
        kayitSirasi.push_back(hasta);
        muayeneSirasi.push(hasta);
    }

    void kayitSirasiYaz()
    {
        if (kayitSirasi.empty())
        {
            cout << " Kayıtlı hasta yok" << endl;
        }
        else
        {
            list<Hasta>::iterator iter = kayitSirasi.begin();
            while (iter != kayitSirasi.end())
            {

                Hasta hasta = *iter;
                hasta.print();
                iter++;
                cout << endl;
            }
            cout << endl;
        }
    }
    void muayeneSirasiYaz()
    {
        cout << "muayene sırası: " << endl;
        if (kayitSirasi.empty())
        {
            cout << " Kayıtlı hasta yok" << endl;
        }
        else
        {
            priority_queue<Hasta> kuyruk = muayeneSirasi;
            while (!kuyruk.empty())
            {
                Hasta hasta = kuyruk.top();
                hasta.print();
                kuyruk.pop();
                cout << endl;
            }
        }
    }
};

int main()

{

    Insan insan("Emre", 24);
    Insan insan2("Ahmet", 22, 1);

    HastaKayit banko;
    banko.kayit(insan);
    banko.kayit(insan2);

    banko.kayitSirasiYaz();
    banko.muayeneSirasiYaz();
}
