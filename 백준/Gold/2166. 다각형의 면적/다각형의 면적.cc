#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> v;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    double result = 0;
    for(int i = 2; i < n; i++)
        result += (v[0].first * v[i - 1].second + v[i - 1].first * v[i].second + v[i].first * v[0].second
                    - v[0].second * v[i - 1].first - v[i - 1].second * v[i].first - v[i].second * v[0].first) / 2;
    result = abs(result);
    cout << fixed;
    cout.precision(1);
    cout << round(result * 10) / 10 << '\n';
    return 0;
}