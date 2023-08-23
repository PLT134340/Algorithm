#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<int> hs;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        hs.insert(num);
    }
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if(hs.find(num) != hs.end())
            hs.erase(num);
        else
            hs.insert(num);
    }

    cout << hs.size() << '\n';
    return 0;
}