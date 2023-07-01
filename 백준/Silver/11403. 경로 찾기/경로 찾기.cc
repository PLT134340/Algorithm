#include <iostream>
using namespace std;

bool edge[100][100] = {false};
bool result[100][100] = {false};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> edge[i][j];
            result[i][j] = edge[i][j];
        }
    
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(result[i][k] && result[k][j])
                    result[i][j] = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}