#include <iostream>
using namespace std;

int distance[999999];
int price[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
        cin >> ::distance[i];
    for(int i = 0; i < n; i++)
        cin >> price[i];
        
    long long result = 0;
    int i = 0;
    while(i < n - 1) {
        int minPrice = price[i];
        int sumDistance = ::distance[i];
        while(minPrice < price[i + 1] && i < n - 1) {
            sumDistance += ::distance[i + 1];
            i++;
        }
        
        result += (long long)minPrice * sumDistance;
        i++;
    }
    cout << result << '\n';
    return 0;
}