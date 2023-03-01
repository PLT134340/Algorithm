#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, r, c;
    cin >> n >> r >> c;

    int result = 0;
    while(n > 0)
    {
        int mid = pow(2, n - 1);
        if(r < mid && c < mid) {}
        else if(r < mid && c >= mid)
        {
            c -= mid;
            result += mid * mid;
        }
        else if(r >= mid && c < mid)
        {
            r -= mid;
            result += 2 * mid * mid;
        }
        else
        {
            r -= mid;
            c -= mid;
            result += 3 * mid * mid;
        }
        n--;
    }

    cout << result << endl;
    return 0;
}