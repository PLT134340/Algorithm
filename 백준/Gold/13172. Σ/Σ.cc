#include <iostream>
using namespace std;

const int MOD = 1000000007;

int extendedEuclid(int a, int b);

int main() {
    int m;
    cin >> m;
    long long sum = 0;
    for(int i = 0; i < m; i++) {
        int n, s;
        cin >> n >> s;
        sum += (long long)s * extendedEuclid(MOD, n);
        sum %= MOD;
    }
    
    cout << sum << '\n';
    return 0;
}

int extendedEuclid(int a, int b) {
    // b^(-1) (mod a), 모듈러 연산의 역원을 반환
    int r1 = a;
    int r2 = b;
    int t1 = 0;
    int t2 = 1;
    while (r2 > 0) {
        int q = r1 / r2;
        int r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        int t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (r1 != 1)
        return 0;
    if (t1 < 0)
        t1 = a + t1;
    return t1;
}
