#include <iostream>
#include <vector>
using namespace std;

bool arr[4000001] = {true, true};

int main() {
    int n;
    cin >> n;
    
    vector<int> prime;
    prime.push_back(0);
    for (int i = 2; i <= n; i++) 
        if (arr[i] == false) {  // 소수이면
            for (int j = 2; i * j <= n; j++)
                arr[i * j] = true;  // 소수의 배수는 합성수임
            prime.push_back(prime.back() + i);
        }
        
    // for (auto p : prime)
    //     cout << p << ' ';
    // cout << '\n';
    
    int count = 0;
    int left = 0;
    int right = 0;
    while (right < prime.size()) {
        int sub = prime[right] - prime[left];
        if (sub > n)
            left++;
        else if (sub < n)
            right++;
        else {
            left++;
            right++;
            count++;
        }
    }
    
    cout << count << '\n';
    return 0;
}