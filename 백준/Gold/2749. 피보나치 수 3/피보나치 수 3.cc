#include <iostream>
#include <map>
using namespace std;

const int MOD = 1000000;

struct Matrix {
    long long n00;
    long long n01;
    long long n10;
    long long n11;
    
    const Matrix operator*(const Matrix &ref) const {
        return Matrix {
            (n00 * ref.n00 + n01 * ref.n10) % MOD, 
            (n00 * ref.n10 + n01 * ref.n11) % MOD,
            (n01 * ref.n00 + n11 * ref.n10) % MOD,
            (n10 * ref.n01 + n11 * ref.n11) % MOD
        };
    }
};

map<long long, Matrix> m;

Matrix pow(long long n);

int main() {
    long long n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    
    m.insert({1, Matrix{1, 1, 1, 0}});
    
    Matrix result = pow(n - 1);
    cout << result.n00 << '\n';
    return 0;
}

Matrix pow(long long n) {
    if (m.find(n) != m.end())
        return m[n];
    
    if (n % 2 == 0)
        m.insert({n, pow(n / 2) * pow(n / 2)});
    else
        m.insert({n, pow((n - 1) / 2) * pow((n - 1) / 2) * m[1]});
    return m[n];
}