#include <iostream>
#include <deque>
using namespace std;

bool isBroken[11] = {false};
bool isPromising(int num);

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        isBroken[tmp] = true;
    }
    if(m == 10) {
        cout << abs(n - 100) << endl;
        return 0;
    }

    int small, big;
    small = big = n;
    while(!isPromising(small) && small >= 0)
        small--;
    while(!isPromising(big) && big < 1000000)
        big++;
    if(small < 0)
        small = 100;

    int tmp = small;
    int smallLength = 0;
    if(tmp == 0)
        smallLength++;
    while(tmp != 0) {
        smallLength++;
        tmp /= 10;
    }
    tmp = big;
    int bigLength = 0;
    if(tmp == 0)
        bigLength++;
    while(tmp != 0) {
        bigLength++;
        tmp /= 10;
    }
    
    int result;
    if(abs(n - small) + smallLength < abs(big - n) + bigLength)
        result = abs(n - small) + smallLength;
    else
        result = abs(big - n) + bigLength;

    if(abs(n - 100) <= result)
        cout << abs(n - 100) << endl;
    else
        cout << result << endl;
    return 0;
}

bool isPromising(int num) {
    if(num == 0 && isBroken[0])
        return false;

    deque<int> dq;
    while(num != 0) {
        dq.push_front(num % 10);
        num /= 10;
    }

    for(int i = 0; i < dq.size(); i++)
        if(isBroken[dq[i]])
            return false;
    
    return true;
}