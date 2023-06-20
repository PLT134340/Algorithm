#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    
    int two = 0;
    int five = 0;
    for(int i = 1; i <= num; i++) {
        int tmp = i;
        while(tmp % 5 == 0 || tmp % 2 == 0)
            if(tmp % 5 == 0) {
                tmp /= 5;
                five++;
            } else if(tmp % 2 == 0) {
                tmp /= 2;
                two++;
            }
    }

    int result = min(two, five);
    cout << result << endl;
    return 0;
}