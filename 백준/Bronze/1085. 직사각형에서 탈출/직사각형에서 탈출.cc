#include <iostream>
using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int minX = x < w - x ? x : w - x;
    int minY = y < h - y ? y : h - y;
    int result = minX < minY ? minX : minY;
    cout << result;
    return 0;
}