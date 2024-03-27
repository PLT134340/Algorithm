#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, l;
    cin >> n >> l;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    
    int result = 0;
    vector<int> up;
    vector<int> down;
    for (int i = 0; i < n; i++) {
        bool can_pass = true;
        up.push_back(matrix[i][0]);
        
        for (int j = 1; j < n; j++) {
            int sub = matrix[i][j - 1] - matrix[i][j];
            
            if (abs(sub) > 1) {
                can_pass = false;
                break;
            } else if (sub == -1) {
                if (up.size() < l) {
                    can_pass = false;
                    break;
                }
                up.clear();
            } else if (sub == 1) {
                if (!down.empty()) {
                    can_pass = false;
                    break;
                }
                up.clear();
                down.push_back(matrix[i][j]);
            } else if (!down.empty())
                down.push_back(matrix[i][j]);
            
            up.push_back(matrix[i][j]);
            if (down.size() == l) {
                up.clear();
                down.clear();
            }
        }
        
        if (can_pass && down.empty()) {
            result++;
            // cout << "row: " << i << '\n';
        }
        
        up.clear();
        down.clear();
    }
    
    for (int i = 0; i < n; i++) {
        bool can_pass = true;
        up.push_back(matrix[0][i]);
        
        for (int j = 1; j < n; j++) {
            int sub = matrix[j - 1][i] - matrix[j][i];
            
            if (abs(sub) > 1) {
                can_pass = false;
                break;
            } else if (sub == -1) {
                if (up.size() < l) {
                    can_pass = false;
                    break;
                }
                up.clear();
            } else if (sub == 1) {
                if (!down.empty()) {
                    can_pass = false;
                    break;
                }
                up.clear();
                down.push_back(matrix[j][i]);
            } else if (!down.empty())
                down.push_back(matrix[j][i]);
            
            up.push_back(matrix[j][i]);
            if (down.size() == l) {
                up.clear();
                down.clear();
            }
        }
        
        if (can_pass && down.empty()) {
            result++;
            // cout << "col: " << i << '\n';
        }
        
        up.clear();
        down.clear();
    }
    
    cout << result << '\n';
    return 0;
}