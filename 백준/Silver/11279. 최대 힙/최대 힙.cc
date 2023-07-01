#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x != 0)
            pq.push(x);
        else if(!pq.empty()) {
            cout << pq.top() << '\n';
            pq.pop();
        } else
            cout << 0 << '\n';
    }
    return 0;
}