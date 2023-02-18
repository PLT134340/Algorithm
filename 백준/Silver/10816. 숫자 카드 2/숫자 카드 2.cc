#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        auto it = mp.find(tmp);
        if(it == mp.end())
            mp.insert(make_pair(tmp, 1));
        else
        {
            int count = it->second;
            mp.erase(tmp);
            mp.insert(make_pair(tmp, count + 1));
        }
    }
    
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        cout << mp.find(tmp)->second << ' ';
    }
    return 0;
}