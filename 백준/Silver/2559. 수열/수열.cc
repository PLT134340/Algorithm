#include <iostream>
using namespace std;

int sum[100001] = {0};

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    
    int max = INT32_MIN;
    for(int i = k; i <= n; i++) {
        int tmp = sum[i] - sum[i - k];
        if(max < tmp)
            max = tmp;
    }
    cout << max << '\n';
    return 0;
}