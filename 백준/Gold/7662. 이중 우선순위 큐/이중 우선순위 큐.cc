#include <iostream>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int k;
        cin >> k;
        multiset<int> ms;
        for(int j = 0; j < k; j++) {
            char c;
            int n;
            cin >> c >> n;

            if(c == 'I')
                ms.insert(n);
            else if(ms.empty())
                continue;
            else if(n == 1)
                ms.erase(prev(ms.end()));
            else if(n == -1)
                ms.erase(ms.begin());
        }

        if(ms.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
    }
    return 0;
}