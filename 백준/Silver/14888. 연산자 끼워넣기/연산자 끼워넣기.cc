#include <iostream>
using namespace std;

int num[11] = {0};
int maxNumOprt[4] = {0};
int numOfOprt[4] = {0};
int max = INT32_MIN;
int min = INT32_MAX;

void calculate(int result, int lv, int end);

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    for(int i = 0; i < 4; i++)
        cin >> maxNumOprt[i];

    calculate(num[0], 1, n);
    
    cout << ::max << '\n';
    cout << ::min << '\n';
    return 0;
}

void calculate(int result, int lv, int end) {
    if(lv == end) {
        if(::max < result)
            ::max = result;
        if(::min > result)
            ::min = result;
        return;
    }

    if(++numOfOprt[0] <= maxNumOprt[0])
        calculate(result + num[lv], lv + 1, end);
    numOfOprt[0]--;

    if(++numOfOprt[1] <= maxNumOprt[1])
        calculate(result - num[lv], lv + 1, end);
    numOfOprt[1]--;
    
    if(++numOfOprt[2] <= maxNumOprt[2])
        calculate(result * num[lv], lv + 1, end);
    numOfOprt[2]--;

    if(++numOfOprt[3] <= maxNumOprt[3])
        calculate(result / num[lv], lv + 1, end);
    numOfOprt[3]--;
}