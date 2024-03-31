#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<bool>> is_wall;
vector<vector<bool>> is_cleaned;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct Cleaner {
    int r;
    int c;
    int d;
    int cleaned_space;
    
    bool is_near_cleaned() {
        for (int i = 0; i < 4; i++)
            if (!is_cleaned[r + dy[i]][c + dx[i]])
                return false;
        return true;
    }
    
    void clean() {
        if (is_cleaned[r][c])
            return;
        
        is_cleaned[r][c] = true;
        cleaned_space++;
        // cout << "clean\n";
    }
    
    void turn() {
        d--;
        if (d == -1)
            d = 3;
        // cout << "turn\n";
    }
    
    void go() {
        int new_r = r + dy[d];
        int new_c = c + dx[d];
        
        if (!is_cleaned[new_r][new_c]) {
            r = new_r;
            c = new_c;
            // cout << "go\n";
        }
    }
    
    bool back() {
        r -= dy[d];
        c -= dx[d];
        
        if (!is_wall[r][c]) {
            // cout << "back\n";
            return true;
        }
        return false;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    
    int r, c, d;
    cin >> r >> c >> d;
    
    Cleaner cleaner{r, c, d, 0};
    is_wall = vector<vector<bool>>(n, vector<bool>(m)); 
    is_cleaned = vector<vector<bool>>(n, vector<bool>(m));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            is_wall[i][j] = is_cleaned[i][j] = tmp;
        }
    
    // cout << '\n';
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++)
    //         cout << is_wall[i][j] << ' ';
    //     cout << '\n';
    // }
    
    while (true) {
        // cout << cleaner.r << ' ' << cleaner.c << ' ' << cleaner.d << '\n';
        cleaner.clean();
        if (cleaner.is_near_cleaned()) {
            if (cleaner.back())
                continue;
            break;
        }
        cleaner.turn();
        cleaner.go();
    }
    cout << cleaner.cleaned_space << '\n';
    return 0;
}