#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int start = 1, end = k;
    while (start < end) {  
        int mid = (start + end) / 2; 
         
        int num = 0;
        for (int i = 1; i <= n; i++)
            num += min(mid / i, n);
        
        if (num < k)
            start = mid + 1;
        else
            end = mid;
    }
    
    cout << start << '\n';
    return 0;
}