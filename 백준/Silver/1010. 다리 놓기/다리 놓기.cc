#include <iostream>
using namespace std;

int binomialCoefficient(int n, int m);

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        cout << binomialCoefficient(m, n) << '\n';
    }
    return 0;
}

int binomialCoefficient(int n, int m) {
    static int arr[31][31] = {0};
    if(arr[n][m] != 0)
        return arr[n][m];
    else if(n == 0 || m == 0 || n == m)
        return arr[n][m] = 1;
    else
        return arr[n][m] = binomialCoefficient(n - 1, m - 1)  + binomialCoefficient(n - 1, m);
}