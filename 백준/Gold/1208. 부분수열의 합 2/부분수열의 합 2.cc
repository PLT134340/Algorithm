#include <iostream>
using namespace std;

long long arr[8000001] = {0};

int main() {
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        
        if(tmp >= 0)
            for(int j = 8000000 - tmp; j >= 0; j--)
                arr[j + tmp] += arr[j];
        else
            for(int j = -tmp; j <= 8000000; j++)
                arr[j + tmp] += arr[j];
        arr[tmp + 4000000]++;
    }
    cout << arr[s + 4000000] << '\n';
    return 0;
}