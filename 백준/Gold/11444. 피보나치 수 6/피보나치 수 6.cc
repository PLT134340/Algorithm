#include <iostream>
#include <map>
using namespace std;

#define MOD 1000000007

long long fib(map<long long, long long>& m, long long n);

int main() {
    long long n;
    cin >> n;

    map<long long, long long> m;
    m.insert({0, 0});
    m.insert({1, 1});
    m.insert({2, 1});

    cout << fib(m, n) << '\n';
    return 0;
}

long long fib(map<long long, long long>& m, long long n) {
    if(m.find(n) != m.end())
        return m[n];
    else if(n % 2 == 0) {
        m.insert({n, (fib(m, n / 2) * (fib(m, n / 2 + 1) + fib(m, n / 2 - 1))) % MOD});
        return m[n];
    } else {
        m.insert({n, ((fib(m, (n + 1) / 2) * fib(m, (n + 1) / 2)) % MOD + (fib(m, (n - 1) / 2) * fib(m, (n - 1) / 2)) % MOD) % MOD});
        return m[n];
    }
}