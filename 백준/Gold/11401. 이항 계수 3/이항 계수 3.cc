#include <iostream>
#define MOD 1000000007
using namespace std;

long long power(int num, int exp);

int main() {
    int n, k;
    cin >> n >> k;

    long long numerator = 1;
    long long denominator = 1;
    for (int i = 2; i <= n; i++)
        numerator = numerator * i % MOD;
    for (int i = 2; i <= k; i++)
        denominator = denominator * i % MOD;
    for (int i = 2; i <= n - k; i++)
        denominator = denominator * i % MOD;

    int result = numerator * power(denominator, MOD - 2) % MOD;
    cout << result << '\n';
    return 0;
}

long long power(int num, int exp) {
    if (exp == 0)
        return 1;
    else if (exp == 1)
        return num % MOD;
    else if(exp % 2 == 0) {
        long long result = power(num, exp / 2);
        return result * result % MOD;
    } else
        return power(num, exp - 1) * num % MOD;
}