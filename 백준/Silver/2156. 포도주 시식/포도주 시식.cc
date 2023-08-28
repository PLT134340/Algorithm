#include <iostream>
using namespace std;

int arr[10001] = {0};
int dp[10001] = {0};

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    int result = max(dp[1], dp[2]);
    for(int i = 3; i <= n; i++) {
        int num1 = dp[i - 3] + arr[i - 1] + arr[i];
        int num2 = dp[i - 2] + arr[i];
        int num3 = dp[i - 1];
        dp[i] = max(max(num1, num2), num3);
    }

    cout << dp[n] << '\n';
    return 0;
}