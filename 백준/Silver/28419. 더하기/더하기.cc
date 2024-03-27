#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        
        if (i % 2 == 1)
            sum += tmp;
        else
            sum -= tmp;
    }
    
    if (n == 3 && sum > 0)
        cout << -1;
    else
        cout << (sum > 0 ? sum : -sum) << '\n';
    return 0;
}