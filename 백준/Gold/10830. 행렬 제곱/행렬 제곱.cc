#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<vector<int>>> m;

vector<vector<int>>& divideMultiply(int n, long long b);
vector<vector<int>> multiplyMatrix(int n, vector<vector<int>>& a, vector<vector<int>>& b);

int main() {
    int n;
    long long b;
    cin >> n >> b;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            matrix[i][j] %= 1000;
        }
    m.insert({1, matrix});
    
    vector<vector<int>> result = divideMultiply(n, b);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

vector<vector<int>>& divideMultiply(int n, long long b) {
    if(m.find(b) != m.end())
        return m[b];
    else {
        m[b / 2] = divideMultiply(n, b / 2);
        m[b - b / 2] = divideMultiply(n, b - b / 2);
        return m[b] = multiplyMatrix(n, m[b / 2], m[b - b / 2]);
    }
}

vector<vector<int>> multiplyMatrix(int n, vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> newMatrix(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++)
                newMatrix[i][j] += (a[i][k] * b[k][j]) % 1000;
            newMatrix[i][j] %= 1000;
        }
    return std::move(newMatrix);
}