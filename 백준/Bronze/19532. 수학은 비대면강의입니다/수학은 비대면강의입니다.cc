#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    int x = (c * e - b * f ) / (a * e - d * b);
    int y;
    if(b != 0)
        y = (c - a * x) / b;
    else
        y = (f - d * x) / e;
    cout << x << ' ' << y << '\n';
    return 0;
}