#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int tmp;
    int sum = 0;
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
        if(tmp > max)
            max = tmp;
    }
    double result = (double)sum * 100 / (max * n);
    cout << result;
    return 0;
}