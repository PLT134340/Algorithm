#include <iostream>
using namespace std;

int arr[100000];
int dp[100000] = {0};

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int max = dp[0] = arr[0];
    for(int i = 1; i < n; i++) {
        if(dp[i - 1] > 0)
            dp[i] = dp[i - 1] + arr[i];
        else
            dp[i] = arr[i];
        
        if(max < dp[i])
            max = dp[i];
    }
    cout << max << '\n';
    return 0;
}