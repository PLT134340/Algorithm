#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    list<string> l[51];
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        int len = str.length();
        l[len].push_back(str);
    }
    
    for(int i = 0; i < 51; i++)
    {
        l[i].sort();
        l[i].unique();
        for(auto j = l[i].begin(); j != l[i].end(); j++)
            cout << *j << endl;
    }
    
    return 0;
}