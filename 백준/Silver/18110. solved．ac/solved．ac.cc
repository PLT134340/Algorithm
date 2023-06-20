#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 0) {
        cout << "0" << endl;
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int exclude = (int)round(n * 0.15);
    for(int i = 0; i < exclude; i++)
        pq.pop();
    long long sum = 0;
    for(int i = exclude; i < n - exclude; i++){
        sum += pq.top();
        pq.pop();
    }
    
    cout << (int)round((double)sum / (n - 2 * exclude)) << endl;
    return 0;
}