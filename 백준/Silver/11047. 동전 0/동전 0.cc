#include <iostream>
using namespace std;

int coin[10];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < 10; i++)
        cin >> coin[i];
    
    int count = 0;
    for(int i = n - 1; i >= 0 && k > 0; i--)
        while(k >= coin[i]) {
            count += k / coin[i];
            k %= coin[i];
        }
    
    cout << count << '\n';
    return 0;
}