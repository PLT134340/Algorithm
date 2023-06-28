#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int max = lcm(m, n);
        while(x != y && x <= max && y <= max)
            if(x < y)
                x += m;
            else
                y += n;
        
        if(x == y)
            cout << x << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}

int gcd(int a, int b) {
    if(a < b)
        swap(a, b);
    
    while(b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}