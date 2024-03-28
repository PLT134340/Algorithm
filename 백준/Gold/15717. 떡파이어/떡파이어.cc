#include <iostream>
#include <map>
using namespace std;

const int MOD = 1000000007;

map<long long, long long> m;

long long recurs(long long n);

int main() {
    long long n;
    cin >> n;
    
    if (n == 0) {
        cout << 1 << '\n';
        return 0;
    }
    
    m.insert({0, 1});
    m.insert({1, 2});
    
    cout << recurs(n - 1) << '\n';
    return 0;
}

long long recurs(long long n) {
    if (m.find(n) != m.end())
        return m[n];
    
    if (n % 2 == 0) {
        if (m.find(n / 2) == m.end())
            m.insert({n / 2, recurs(n / 2)});
        return (m[n / 2] * m[n / 2]) % MOD;
    } else {
        if (m.find((n - 1) / 2) == m.end())
            m.insert({(n - 1) / 2, recurs((n - 1) / 2)});
        return (m[(n - 1) / 2] * m[(n - 1) / 2]) * 2 % MOD;
    }
}