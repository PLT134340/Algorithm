#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<long long>> v(n + 1, vector<long long>(2, 0));
    v[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        v[i][0] = v[i - 1][0] + v[i - 1][1];
        v[i][1] = v[i - 1][0];
    }
    
    cout << v[n][0] + v[n][1] << '\n';
    return 0;
}