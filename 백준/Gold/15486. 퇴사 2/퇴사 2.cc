#include <iostream>
#include <queue>
using namespace std;

int dp[1500001] = {0};

struct node {
    int start;
    int end;
    int value;
};

struct compare {
    bool operator()(const node& n1, const node& n2) const {
        return n1.end > n2.end;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<node, vector<node>, compare> pq;
    for(int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;
        pq.push(node{i, i + t - 1, p});
    }

    node nd = pq.top();
    pq.pop();
    for(int i = 1; i <= n; i++)
        if(i == nd.end) {
            int result = dp[nd.start - 1] + nd.value;
            if(dp[nd.end] < result)
                dp[nd.end] = result;
            
            if(!pq.empty()) {
                nd = pq.top();
                pq.pop();
                i--;
            }
        } else if(dp[i] < dp[i - 1])
            dp[i] = dp[i - 1];

    cout << dp[n] << '\n';
    return 0;
}