#include <iostream>
#include <map>

using namespace std;

/*
Maps are associative containers that store elements in a mapped fashion.
Each element has a key value and a mapped value. No two mapped values can have same key values.

*/
template <typename T>
void print(T &t, string sep = " ")
{
    typename T::iterator iter = t.begin();
    while (iter != t.end())
    {
        cout << iter->first << " " << iter->second << sep;
        iter++;
    }
    cout << endl;
}

template <typename T>
bool cmp(T x, T y)
{
    return x > y;
}

int main()
{

    //map<string, int, bool (*)(string, string)> m(cmp);
    map<string, int> m;

    pair<string, int> deger("bir", 1); // aynı eleman iki kere eklenmez.(multimap)
    pair<string, int> deger1("iki", 2);
    m.insert(deger);
    m.insert(deger1);
    print(m, "\n");

    pair<string, int> pa[] = {
        pair<string, int>("uc", 3),
        pair<string, int>("dort", 4),
        pair<string, int>("bes", 5)};

    m.insert(pa, pa + 3);
    print(m, "\n");

    map<string, int>::iterator end, begin = m.begin();
    end = m.end();

    cout << begin->first << " " << begin->second << endl;

    decltype(end) iter = m.find("uc");
    cout << iter->first << endl;

    decltype(end) up, low;
    up = m.upper_bound("iki");
    low = m.lower_bound("bir");

    cout << up->second << endl; //ikinin bir sonraki elemanı
    cout << low->second << endl;

    pair<map<string, int>::iterator, map<string, int>::iterator> eq = m.equal_range("iki");
    cout << eq.first->second << endl;  //lower
    cout << eq.second->second << endl; //upper

    cout << "erase: " << endl;
    // m.erase(low);
    m.erase(low, up); //1 ile 2 arası silindi.
    print(m);

    cout << m["uc"] << endl;

    //multimap
    multimap<string, int> multi;
    pair<string, int> mu("bir", 1);
    multi.insert(mu);
    multi.insert(pair<string, int>("bir", 1));
    multi.insert(pair<string, int>("iki", 2));
    multi.insert(pair<string, int>("uc", 3));
    multi.insert(pair<string, int>("uc", 3));
    print(multi);

    multimap<string, int>::iterator a, b, c, d;
    a = multi.lower_bound("uc");
    b = multi.upper_bound("uc");

    pair<decltype(a), decltype(a)> range = multi.equal_range("bir");
    multi.erase(range.first, range.second);
    print(multi);
}
