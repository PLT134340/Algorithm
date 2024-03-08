#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct PriorityQueue {
    
    int mid = INT32_MAX;
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    void push(int value) {
        if (mid == INT32_MAX) {
            mid = value;
            return;
        }
        
        if (value < mid)
            left.push(value);
        else
            right.push(value);
        
        int leftSize = left.size();
        int rightSize = right.size();
        
        if (leftSize > rightSize) {
            right.push(mid);
            mid = left.top();
            left.pop();
        } else if (leftSize + 1 < rightSize) {
            left.push(mid);
            mid = right.top();
            right.pop();
        }
        
    }
    
    void print() {
        if (!left.empty())
            cout << "leftTop: " << left.top() << '\n';
        cout << "mid: " << mid << '\n';
        if (!right.empty())
            cout << "rightTop: " << right.top() << '\n';
    }
    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    PriorityQueue pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        cout << pq.mid << '\n';
        // pq.print();
    }
    return 0;
}