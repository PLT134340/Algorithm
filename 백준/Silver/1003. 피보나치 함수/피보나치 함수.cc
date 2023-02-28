#include <iostream>
using namespace std;

int zero[41] = {1, 0};
int one[41] = {0, 1};

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for(int j = 2; j <= n; j++)
            if(zero[j] == 0 && one[j] == 0)
            {
                zero[j] = zero[j - 1] + zero[j - 2];
                one[j] = one[j - 1] + one[j - 2];
            }
        cout << zero[n] << ' ' << one[n] << '\n';
    }
    return 0;
}