#include <iostream>
#include <queue>
using namespace std;

int visitedTime[100001];

int main() {
    for (int i = 0; i < 100001; i++)
        visitedTime[i] = INT32_MAX;

    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q; // {location, time}
    q.push({n, 0});
    int minTime = -1;
    int count = 0;
    while (!q.empty()) {
        auto [location, time] = q.front();
        q.pop();

        if (location == k && count == 0) {
            minTime = time;
            count++;
        } else if (location == k && time == minTime)
            count++;

        int newLocation[3] = {location - 1, location + 1, 2 * location};
        for (int i = 0; i < 3; i++)
            if (count == 0 && newLocation[i] >= 0 && newLocation[i] <= 100000 && time <= visitedTime[newLocation[i]]) {
                q.push({newLocation[i], time + 1});
                visitedTime[newLocation[i]] = time;
            }
    }

    cout << minTime << '\n'
         << count << '\n';
    return 0;
}