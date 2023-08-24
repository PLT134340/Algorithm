#include <iostream>
#include <vector>
using namespace std;

int arr[1000] = {0};

void injectionSort(int n);

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    injectionSort(n);

    cout << arr[k - 1] << '\n';
    return 0;
}

void injectionSort(int n) {
    for(int i = 1; i < n; i++)
        for(int j = i - 1; j >= 0 && arr[j] < arr[j + 1]; j--)
            swap(arr[j], arr[j + 1]);
}