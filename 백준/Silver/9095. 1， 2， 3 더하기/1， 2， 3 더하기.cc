#include <iostream>
using namespace std;

int arr[12] = {0, 1, 2, 4};

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        for(int j = 4; j <= n; j++) {
            if(arr[j] == 0)
                for(int k = 0; k < 3; k++)
                    arr[j] += arr[j - k - 1];
        }
        cout << arr[n] << '\n';
    }
    return 0;
}