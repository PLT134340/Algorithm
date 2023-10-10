#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    bool isExist[1000001] = {false};
    int arr[100001];
    int score[1000001] = {0};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        isExist[arr[i]] = true;
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 2 * arr[i]; j <= 1000000; j += arr[i])
            if(isExist[j]) {
                score[arr[i]]++;
                score[j]--;
            }
    
    for(int i = 0; i < n; i++)
        cout << score[arr[i]] << ' ';
    return 0;
}