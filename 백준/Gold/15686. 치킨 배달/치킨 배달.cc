#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int selectedChicken[13] = {0};
int minResult = INT32_MAX;

void selectChicken(int size, int idx);
void calculateDistance();

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                home.push_back({i, j});
            else if (tmp == 2)
                chicken.push_back({i, j});
        }
    
    selectChicken(0, 0);
    cout << minResult << '\n';
    return 0;
}

void selectChicken(int size, int idx) {
    if (size == m) {
        calculateDistance();
        return;
    } else if (idx == chicken.size())
        return;

    selectChicken(size, idx + 1);
    selectedChicken[size] = idx;
    selectChicken(size + 1, idx + 1);
}

void calculateDistance() {
    int sum = 0;
    int numHome = home.size();
    for (int i = 0; i < numHome; i++) {
        int tmp = INT32_MAX;
        for (int j = 0; j < m; j++) {
            auto [homeY, homeX] = home[i];
            auto [chickenY, chickenX] = chicken[selectedChicken[j]];
            int distance = abs(homeY - chickenY) + abs(homeX - chickenX);
            if (tmp > distance)
                tmp = distance;
        }
        sum += tmp;
    }

    if (minResult > sum)
        minResult = sum;
}