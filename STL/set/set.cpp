#include <iostream>
#include <set>
#include <vector>
#include <list>

using namespace std;

/*
Sets are a type of associative containers in which each element has to be unique, because the value of the element
identifies it.The value of the element cannot be modified once it is added to the set, though it is possible to remove
and add the modified value of that element. 
*/

template <typename T>
void print(T &t)
{
    typename T::iterator iter = t.begin();
    while (iter != t.end())
    {
        cout << *iter++ << " ";
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
    set<int> s;
    cout << "empty: " << s.empty() << endl;

    cout << "insert: " << endl;
    s.insert(8); // sadece insert metodu ile ekleme yapılır
    s.insert(8); // aynı eleman iki kere eklenmez
    print(s);

    set<int>::iterator it = s.begin();
    it = s.insert(it, 222);
    print(s);

    int arry[] = {1, 2, 3, 4, 5};
    s.insert(arry, arry + 5);
    print(s);

    vector<int> v;
    v.push_back(3);
    v.push_back(99);
    s.insert(v.begin(), v.end());
    print(s);

    set<int>::iterator begin = s.begin();
    cout << "begin: " << *begin << endl;

    cout << "erase " << endl;
    s.erase(it);
    print(s);

    //s.clear();
    cout << s.size() << endl;

    //find
    set<int>::iterator n = s.find(5);
    if (n != s.end())
    {
        cout << "eleman var" << endl;
    }
    else
    {
        cout << " eleman yok" << endl;
    }
    cout << *n << endl;
    s.erase(n);
    print(s);
    cout << "size: " << s.size() << endl;

    set<int, greater<int>> s2;
    s2.insert(s.begin(), s.end());
    print(s2);

    set<int, bool (*)(int, int)> s3(cmp);
    s3.insert(8);
    s3.insert(99);
    s3.insert(100);
    print(s3);

    //multiset
    multiset<int> m; // kümede birden fazla aynı eleman bulunabilir
    m.insert(3);
    m.insert(3);
    m.insert(5);
    m.insert(7);
    m.insert(7);
    print(m);
    cout << "count: " << m.count(3) << endl;

    multiset<int>::iterator up, low;
    low = m.lower_bound(7);
    up = m.upper_bound(7);
    m.erase(low, up);
    print(m);

    multiset<int>::iterator iter;
    pair<decltype(iter), decltype(iter)> range = m.equal_range(3);
    print(m);
    m.erase(range.first, range.second);
    print(m);
}