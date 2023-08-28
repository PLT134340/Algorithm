#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int maxWeight = INT32_MIN;
    int minWeight = INT32_MAX;
    priority_queue<int> positive;
    priority_queue<int, vector<int>, greater<int>> negative;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if(num > 0) {
            positive.push(num);
            if(maxWeight < num)
                maxWeight = num;
        } else {
            negative.push(num);
            if(minWeight > num)
                minWeight = num;
        }
    }

    int result = 0;
    if(maxWeight > abs(minWeight) || minWeight == INT32_MAX) {
        result += positive.top();
        for(int i = 0; i < m; i++)
            if(positive.empty())
                break;
            else
                positive.pop();
    } else if(maxWeight <= abs(minWeight) || maxWeight == INT32_MIN) {
        result += -negative.top();
        for(int i = 0; i < m; i++)
            if(negative.empty())
                break;
            else
                negative.pop();
    }

    while(!positive.empty()) {
        result += 2 * positive.top();
        for(int i = 0; i < m; i++)
            if(positive.empty())
                break;
            else
                positive.pop();
    }
    while(!negative.empty()) {
        result += -2 * negative.top();
        for(int i = 0; i < m; i++)
            if(negative.empty())
                break;
            else
                negative.pop();
    }

    cout << result << '\n';
    return 0;
}