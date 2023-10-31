#include <iostream>
using namespace std;

int arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0;
    int right = n - 1;
    int min = INT32_MAX;
    int answer[2];
    while (left < right && left >= 0 && right < n) {
        int sum = arr[left] + arr[right];

        if (min > abs(sum)) {
            min = abs(sum);
            answer[0] = arr[left];
            answer[1] = arr[right];
        }

        if (sum > 0)
            right--;
        else if (sum < 0)
            left++;
        else {
            answer[0] = arr[left];
            answer[1] = arr[right];
            break;
        }
    }

    cout << answer[0] << ' ' << answer[1] << '\n';
    return 0;
}