#include <iostream>
using namespace std;

int arr[10] = {0};

void injectionSort(int n);

int main() {
    int n;
    cin >> n;

    int count = 0;
    for(int i = 0; i < 10 && n != 0; i++) {
        arr[i] = n % 10;
        n /= 10;
        count++;
    }

    injectionSort(count);

    for(int i = 0; i < count; i++)
        cout << arr[i];
    cout << '\n';
    return 0;
}

void injectionSort(int n) {
    for(int i = 1; i < n; i++)
        for(int j = i - 1; j >= 0 && arr[j] < arr[j + 1]; j--)
            swap(arr[j], arr[j + 1]);
}