#include <iostream>
using namespace std;

int arr[50001] = {0};

int main() {
    int n;
    cin >> n;
    for(int i = 1; i * i <= n; i++)
        for(int j = 1; i * i + j * j <= n; j++)
            arr[i * i + j * j] = 2;
    
    for(int i = 1; i * i <= n; i++)
        arr[i * i] = 1;

    int min = 5;
    for(int i = 1; i <= n; i++) {
        int sum = arr[n - i] + arr[i];
        if(arr[n - i] != 0 && arr[i] != 0 && min > sum)
            min = sum;
    }
    if(arr[n] == 0 || arr[n] > min)
        arr[n] = min;

    cout << arr[n] << '\n';
    return 0;
}