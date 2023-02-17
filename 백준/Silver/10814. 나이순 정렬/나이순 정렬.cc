#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, string>> v;
    for(int i = 0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }
    
    stable_sort(v.begin(), v.end(), [](const pair<int, string> &a, const pair<int, string> &b) {return a.first < b.first;});
    for(int i = 0; i < v.size(); i++)
        cout << v.at(i).first << ' ' << v.at(i).second << '\n';
    return 0;
}