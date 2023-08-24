#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct word {
    int frequency;
    int length;
    string spelling;
};

bool compare(const word& a, const word& b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    multiset<string> ms;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str.size() >= m)
            ms.insert(str);
    }

    vector<word> v;
    int count = 1;
    string prev = "";
    for(auto it = ms.begin(); it != ms.end(); it++)
        if(*it == prev)
            count++;
        else if(prev != "") {
            v.push_back(word{count, (int)prev.size(), prev});
            count = 1;
            prev = *it;
        }
        else
            prev = *it;
    v.push_back(word{count, (int)prev.size(), prev});
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++)
        cout << v[i].spelling << '\n';
    return 0;
}

bool compare(const word& a, const word& b) {
    if(a.frequency == b.frequency && a.length == b.length)
        return a.spelling < b.spelling;
    else if(a.frequency == b.frequency)
        return a.length > b.length;
    else
        return a.frequency > b.frequency;
}