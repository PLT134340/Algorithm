#include <iostream>
#include <set>
using namespace std;

int main() {
    int g, p;
    cin >> g >> p;
    
    multiset<int, greater<int>> hs;
    for(int i = 1; i <= g; i++)
        hs.insert(i);
    
    int result = 0;
    for(int i = 0; i < p; i++) {
        int tmp;
        cin >> tmp;
        
        auto it = hs.lower_bound(tmp);
        if(it != hs.end()) {
            result++;
            hs.erase(it);
        } else
            break;
    }
    
    cout << result << '\n';
    return 0;
}