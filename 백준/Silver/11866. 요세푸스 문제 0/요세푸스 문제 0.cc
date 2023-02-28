#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    list<int> l;
    for(int i = 1; i <= n; i++)
        l.push_back(i);
    list<int>::iterator it = l.begin();
    for(int i = 0; i < k - 1; i++)
    {
        it++;
        if(it == l.end())
            it = l.begin();
    }
    string result = "<" + to_string(*it);
    it = l.erase(it);
    if(it == l.end())
        it = l.begin();
    while(!l.empty())
    {
        for(int i = 0; i < k - 1; i++)
        {
            it++;
            if(it == l.end())
                it = l.begin();
        }
        result += ", " + to_string(*it);
        it = l.erase(it);
        if(it == l.end())
            it = l.begin();
    }
    result += ">";
    cout << result << endl;
    return 0;
}