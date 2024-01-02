#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void recurs(int lv, vector<pair<int, int>> &v, vector<int> &start, double &answer);

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<pair<int, int>> v;
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }

        vector<int> start;
        double answer = 3000000;
        recurs(0, v, start, answer);

        cout.precision(12);
        cout << fixed << answer << '\n';
    }
    return 0;
}

void recurs(int lv, vector<pair<int, int>> &v, vector<int> &start, double &answer) {
    if (start.size() == v.size() / 2) {
        pair<int, int> sum = {0, 0};
        for (int i = 0, j = 0; i < v.size(); i++)
            if (i == start[j]) {
                sum.first -= v[i].first;
                sum.second -= v[i].second;
                j++;
            } else {
                sum.first += v[i].first;
                sum.second += v[i].second;
            }

        double result = sqrt((double)sum.first * sum.first + (double)sum.second * sum.second);
        if (answer > result)
            answer = result;
        return;
    } else if (lv >= v.size())
        return;
    
    recurs(lv + 1, v, start, answer);
    start.push_back(lv);
    recurs(lv + 1, v, start, answer);
    start.pop_back();
}