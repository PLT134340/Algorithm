#include <iostream>
using namespace std;

int main()
{
   int arr[42] = {0};
    for(int i = 0; i < 10; i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp % 42]++;
    }

    int result = 0;
    for(int i = 0; i < 42; i++)
        if(arr[i] != 0)
            result++;
    cout << result;
    return 0;
}