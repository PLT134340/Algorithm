#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment {
    long long x1;
    long long y1;
    long long x2;
    long long y2;
};

vector<Segment> v;
vector<pair<int, int>> root;

void unite(int r1, int r2);
int find(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    v = vector<Segment>(n);
    root = vector<pair<int, int>>(n);
    
    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v[i] = Segment{x1, y1, x2, y2};
        root[i] = {i, 1};
    }
    
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            int root1 = find(i);
            int root2 = find(j);
            
            if (root1 == root2)
                continue;
                
            // cout << "i: " << i << ", j: " << j << '\n';
            // cout << "root1: " << root1 << ", root2: " << root2 << '\n';
            
            long long a1 = v[i].y2 - v[i].y1;
            long long b1 = v[i].x1 - v[i].x2;
            long long c1 = b1 * v[i].y1 + a1 * v[i].x1;
            long long a2 = v[j].y2 - v[j].y1;
            long long b2 = v[j].x1 - v[j].x2;
            long long c2 = b2 * v[j].y1 + a2 * v[j].x1;
            
            // cout << a1 << "x+" << b1 << "y=" << c1 << '\n';
            // cout << a2 << "x+" << b2 << "y=" << c2 << '\n';
            
            long long det = a1 * b2 - b1 * a2;
            // cout << "det: " << det << '\n';
            
            // 일치
            if (det == 0 &&
                    (a1 == 0 && b1 * c2 == b2 * c1 || a1 * c2 == a2 * c1) &&
                    max(v[i].x1, v[i].x2) >= min(v[j].x1, v[j].x2) && max(v[j].x1, v[j].x2) >= min(v[i].x1, v[i].x2) &&
                    max(v[i].y1, v[i].y2) >= min(v[j].y1, v[j].y2) && max(v[j].y1, v[j].y2) >= min(v[i].y1, v[i].y2)) {
                unite(root1, root2);
                // cout << "i: " << i << ", j: " << j << ", det: " << det << '\n'; 
                continue;
            } else if (det == 0)
                continue;
            
            // 교차하는 직선
            long long x = (c1 * b2 - b1 * c2);
            long long y = (a1 * c2 - c1 * a2);
            
            // cout << (double)x / det << ", " << (double)y / det << '\n';
            
            long long x1_i = v[i].x1 * det;
            long long y1_i = v[i].y1 * det;
            long long x2_i = v[i].x2 * det;
            long long y2_i = v[i].y2 * det;
            long long x1_j = v[j].x1 * det;
            long long y1_j = v[j].y1 * det;
            long long x2_j = v[j].x2 * det;
            long long y2_j = v[j].y2 * det;
            
            if ((x >= x1_i && x <= x2_i || x >= x2_i && x <= x1_i) && (y >= y1_i && y <= y2_i || y >= y2_i && y <= y1_i) && 
                    (x >= x1_j && x <= x2_j || x >= x2_j && x <= x1_j) && (y >= y1_j && y <= y2_j || y >= y2_j && y <= y1_j)) {
                unite(root1, root2);
                // cout << "i: " << i << ", j: " << j << ", det: " << det << '\n';
            }   
        }
    
    int count = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
        // cout << root[i].first << ", " << root[i].second << '\n';
        if (root[i].first == i) {
            count++;
            if (max < root[i].second)
                max = root[i].second;
        }
    cout << count << '\n' << max << '\n';
    return 0;
}

void unite(int r1, int r2) {
    if (root[r1].second > root[r2].second) {
        root[r1].second += root[r2].second;
        root[r2].first = r1;
        return;
    }
    
    root[r2].second += root[r1].second;
    root[r1].first = r2;
}

int find(int n) {
    while (n != root[n].first)
        n = root[n].first;
    return n;
}