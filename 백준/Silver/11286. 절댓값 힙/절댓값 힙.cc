#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator()(const int a, const int b) const {
        if(abs(a) > abs(b))
            return true;
        else if(abs(a) == abs(b))
            return a > b;
        else
            return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, compare> pq;
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