#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Pair {
    int y;
    int x;
};

struct node {
    int lv;
    Pair r;
    Pair b;
};

int n, m;
Pair red;
Pair blue;
Pair hole;
vector<vector<bool>> matrix;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void next(int num, Pair &p1, Pair &p2);

int main() {
    cin >> n >> m;
    matrix = vector<vector<bool>>(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            if (str[j] == '#')
                matrix[i][j] = false;
            else if (str[j] == 'O') {
                matrix[i][j] = false;
                hole = Pair{i, j};
            } else {
                matrix[i][j] = true;
                if (str[j] == 'R')
                    red = Pair{i, j};
                else if (str[j] == 'B')
                    blue = Pair{i, j};
            }
    }

    queue<node> q;
    q.push(node{0, red, blue});
    while (!q.empty()) {
        auto [lv, r, b] = q.front();
        q.pop();
        
        // if (lv <= 3)
        //     cout << "lv: " << lv << ", r: (" << r.y << ", " << r.x << "), b: (" << b.y << ", " << b.x << ")\n";
        
        if (r.y == 0 && b.y == 0)
            continue;
        else if (r.y == 0) {
            cout << lv << '\n';
            return 0;
        } else if (lv == 10)
            continue;
        
        for (int i = 0; i < 4; i++) {
            int sum = dy[i] * (r.y - b.y) + dx[i] * (r.x - b.x);
            bool isRedFirst = sum > 0 ? true : false;
            
            Pair newR = Pair(r);
            Pair newB = Pair(b);
            
            if (isRedFirst) {
                next(i, newR, newB);
                next(i, newB, newR);
            } else {
                next(i, newB, newR);
                next(i, newR, newB);
            }
            
            q.push(node{lv + 1, newR, newB});
        }
    }
    
    cout << -1 << '\n';
    return 0;
}

void next(int i, Pair &p1, Pair &p2) {
    if (p1.y == 0)
        return;
        
    while (p1.y + dy[i] >= 0 && p1.y + dy[i] < n && p1.x + dx[i] >= 0 && p1.x + dx[i] < m
            && matrix[p1.y + dy[i]][p1.x + dx[i]] && !(p1.y + dy[i] == p2.y && p1.x + dx[i] == p2.x)) {
        p1.y += dy[i]; 
        p1.x += dx[i];
    }
    
    if (p1.y + dy[i] == hole.y && p1.x + dx[i] == hole.x)
        p1.y = 0;
}