#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    unordered_map<string, string> hm;
    for(int i = 0; i < n; i++) {
        string address, pw;
        cin >> address >> pw;
        hm.insert({address, pw});
    }

    for(int i = 0; i < m; i++) {
        string address;
        cin >> address;
        if(hm.find(address) != hm.end())
            cout << hm[address] << '\n';
    }
    return 0;
}