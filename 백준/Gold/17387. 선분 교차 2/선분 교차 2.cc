#include <iostream>
using namespace std;

int main() {
    long long x1, y1, x2, y2;
    long long x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    long long a1 = y2 - y1;
    long long b1 = x1 - x2;
    long long c1 = (y2 - y1) * x1 - (x2 - x1) * y1;
    long long a2 = y4 - y3;
    long long b2 = x3 - x4;
    long long c2 = (y4 - y3) * x3 - (x4 - x3) * y3;
    
    // cout << a1 << "x + " << b1 << "y = " << c1 << '\n';
    // cout << a2 << "x + " << b2 << "y = " << c2 << '\n';
    
    long long det = a1 * b2 - a2 * b1;
    long long x = c1 * b2 - c2 * b1;
    long long y = a1 * c2 - a2 * c1;
    int result = 2;
    if (det == 0) {
        if ((a1 * a2 == c1 * c2 || c1 == 0 && c2 == 0) &&
            max(x1, x2) >= min(x3, x4) && min(x1, x2) <= max(x3, x4) &&
            max(y1, y2) >= min(y3, y4) && min(y1, y2) <= max(y3, y4))
            result = 1;
        else
            result = 0;
    } else {
        x1 *= det;
        y1 *= det;
        x2 *= det;
        y2 *= det;
        x3 *= det;
        y3 *= det;
        x4 *= det;
        y4 *= det;
        
        if ((x >= x1 && x <= x2 || x <= x1 && x >= x2) && (y >= y1 && y <= y2 || y <= y1 && y >= y2) &&
            (x >= x3 && x <= x4 || x <= x3 && x >= x4) && (y >= y3 && y <= y4 || y <= y3 && y >= y4))
            result = 1;
        else
            result = 0;
    }
        
    cout << result << '\n';
    return 0;
}