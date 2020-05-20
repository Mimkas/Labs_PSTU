#include <iostream>
#include <set>
using namespace std;
typedef set <pair<int, float>> fset;
fset::iterator it;
fset MakeSet()
{
    cout << "N? ";
    int n;
    cin >> n;
    fset f;
    for (int i = 0; i < n;i++)
    {
        float a = rand()*0.01;
        f.insert(make_pair(i, a));
    }
    return f;
}
void PrintSet(fset f)
{
    for (auto& item : f)
    {
        cout << item.first << " " << item.second << "\n";
    }
}
float MinSize(fset f)
{
    float fl = 1000;
    for (auto& item : f)
    {
        if (fl > item.second) fl = item.second;
    }
    return fl;
}
float MaxSize(fset f)
{
    float fl = 0;
    for (auto& item : f)
    {
        if (fl < item.second) fl = item.second;
    }
    return fl;
}
fset AddElem(fset f,float fl)
{
    int i = 0;
    for (auto& item : f) if (i < item.first)i = item.first;
    i++;
    f.insert(make_pair(i, fl));
    return f;
}
fset DeleteElem(fset f)
{
    cout << "put num elem, for search key\t";
    int key;
    cin >> key;
    float fl;
    for (auto& item : f)
    {
        if (item.first == key) fl = item.second;
    }
    it = f.find(make_pair(key, fl));
    if (it != f.end())
    {
        f.erase(it);
    }
    else cout << "key not found.\n";
    return f;
}
fset AddMinMaxElem(fset f)
{
    float fl = MinSize(f) + MaxSize(f);
    fset bof;
    for (auto& item : f)
    {
        bof.insert(make_pair(item.first, item.second + fl));
    }
    return bof;
}
void main()
{
    fset f;
    f = MakeSet();
    PrintSet(f);
    float fl = MinSize(f);
    cout << "\n\n\n";
    cout << fl << "\n";
    cout << "\n\n\n";
    PrintSet(f);
    cout << "\n\n\n";
    f = AddElem(f,fl);
    PrintSet(f);
    cout << "\n\n\n";
    f = DeleteElem(f);
    PrintSet(f);
    cout << "\n\n\n";
    f = AddMinMaxElem(f);
    PrintSet(f);
}
