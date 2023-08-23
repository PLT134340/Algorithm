#include <iostream>
using namespace std;

int main() {
    int count[10] = {0};
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        count[num / 10]++;
        sum += num;
    }

    cout << sum / 5 << '\n';
    int num = 0;
    for(int i = 0; i < 10; i++) {
        num += count[i];
        if(num >= 3) {
            cout << i * 10 << '\n';
            break;
        }
    }
    return 0;
}