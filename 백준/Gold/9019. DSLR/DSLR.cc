#include <iostream>
#include <string>
#include <queue>
using namespace std;

int shiftNum(int n, int shift);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        bool isChecked[10000] = {false};

        int a, b;
        cin >> a >> b;

        queue<pair<int, string>> q;
        q.push({a, ""});
        while(true) {
            auto [n, inst] = q.front();
            q.pop();

            // cout << n << ' ' << inst << '\n';
            
            if(n == b) {
                cout << inst << '\n';
                break;
            }
            
            if(n == 0 && !isChecked[9999]) {
                q.push({9999, inst + "S"});
                isChecked[9999] = true;
            } else if(n != 0) {
                int idx = 2 * n % 10000;
                if(!isChecked[idx]){
                    q.push({idx, inst + "D"});
                    isChecked[idx] = true;
                }

                idx = n - 1;
                if(!isChecked[idx]) {
                    q.push({idx, inst + "S"});
                    isChecked[idx] = true;
                }

                idx = shiftNum(n, -1);
                if(!isChecked[idx]) {
                    q.push({idx, inst + "L"});
                    isChecked[idx] = true;
                }
                
                idx = shiftNum(n, 1);
                if(!isChecked[idx]){
                    q.push({idx, inst + "R"});
                    isChecked[idx] = true;
                }
            }
        }
    }
    return 0;
}

int shiftNum(int n, int shift) {
    int arr[4];
    int tmp = n;
    for(int i = 0; i < 4; i++) {
        arr[3 - i] = tmp % 10;
        tmp /= 10;
    }

    int result = 0;
    if(shift == -1) {
        for(int i = 0; i < 3; i++) {
            result += arr[i + 1];
            result *= 10;
        }
        result += arr[0];
    } else if(shift == 1) {
        result += arr[3];
        for(int i = 0; i < 3; i++) {
            result *= 10;
            result += arr[i];
        }
    }
    return result;
}