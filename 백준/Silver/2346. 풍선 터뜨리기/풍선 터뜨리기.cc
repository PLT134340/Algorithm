#include <iostream>
#include <list>
using namespace std;

int main() {
    int n;
    cin >> n;

    list<pair<int, int>> l;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        l.push_back({i + 1, num});
    }

    auto it = l.begin();
    while(!l.empty()) {
        auto [order, num] = *it;
        cout << order << ' ';

        it = l.erase(it);
        if(it == l.end())
            it = l.begin();
        
        if(num > 0)
            for(int i = 1; i < num; i++) {
                it++;
                if(it == l.end())
                    it = l.begin();
            }
        else
            for(int i = 0; i > num; i--) {
                if(it == l.begin())
                    it = l.end();
                it--;
            }
    }
    cout << '\n';
    return 0;
}