#include <iostream>
using namespace std;

char matrix[100][100];

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> matrix[i];
    
    for (int i = 0; i < m; i++) {
        bool is_escape = true;
        for (int j = 0; j < n; j++) 
            if (matrix[j][i] == 'O') {
                is_escape = false;
                break;
            }
        
        if (is_escape) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << "ESCAPE FAILED\n";
    return 0;
}