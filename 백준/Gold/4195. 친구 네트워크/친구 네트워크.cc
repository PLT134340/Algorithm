#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, pair<string, int>> hm;

void _union(string to, string from);
string find(string f);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int f;
        cin >> f;
        
        for (int j = 0; j < f; j++) {
            string f1, f2;
            cin >> f1 >> f2;
            
            if (hm.find(f1) == hm.end())
                hm.insert({f1, {f1, 1}});
            if (hm.find(f2) == hm.end())
                hm.insert({f2, {f2, 1}});
            
            string f1_root = find(f1);
            string f2_root = find(f2);
            
            if (hm[f1_root].first == hm[f2_root].first) {
                cout << hm[f1_root].second << '\n';
            } else if (hm[f1_root].second > hm[f2_root].second) {
                _union(f1_root, f2_root);
                cout << hm[f1_root].second << '\n';
            } else {
                _union(f2_root, f1_root);
                cout << hm[f2_root].second << '\n';
            }
        }
        
        hm.clear();
    }
    return 0;
}

void _union(string to, string from) {
    hm[to].second += hm[from].second;
    hm[from].first = to;
}

string find(string f) {
    while (f != hm[f].first)
        f = hm[f].first;
    return f;
}