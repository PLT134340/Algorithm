#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    
    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); it++)
        cout << it->first << ' ' << it->second << '\n';
    return 0;
}