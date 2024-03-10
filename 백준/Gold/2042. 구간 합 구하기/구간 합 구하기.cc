#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct SegmentTree {
    vector<long long> tree;
    
    SegmentTree(vector<long long> &num) {
        tree = vector<long long>(num.size() * 4);
        init(num, 0, num.size() - 1, 1);
    }
    
    long long init(vector<long long> &num, int start, int end, int idx) {
        if (start == end)
            return tree[idx] = num[start];
        
        int mid = (start + end) / 2;
        return tree[idx] = init(num, start, mid, idx * 2) + init(num, mid + 1, end, idx * 2 + 1);   
    }
    
    long long set(long long newNum, int pos, int start, int end, int idx) {
        if (pos > end || pos < start)
            return tree[idx];
        else if (start == end)
            return tree[idx] = newNum;
        
        int mid = (start + end) / 2;
        return tree[idx] = set(newNum, pos, start, mid, idx * 2) + set(newNum, pos, mid + 1, end, idx * 2 + 1);
    }
    
    long long sum(int left, int right, int start, int end, int idx) {
        if (left > end || right < start)
            return 0;
        else if (left <= start && right >= end)
            return tree[idx];
        
        int mid = (start + end) / 2;
        return sum(left, right, start, mid, idx * 2) + sum(left, right, mid + 1, end, idx * 2 + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<long long> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    SegmentTree segmentTree = SegmentTree(num);
    
    for (int i = 0; i < m + k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        
        if (a == 1)
            segmentTree.set(c, b - 1, 0, n - 1, 1);
        else
            cout << segmentTree.sum(b - 1, c - 1, 0, n - 1, 1) << '\n';
    }
    
    return 0;
}