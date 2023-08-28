#include <iostream>
#include <unordered_set>
using namespace std;

int synergy[20][20] = {0};
unordered_set<int> team1;
unordered_set<int> team2;
int min = INT32_MAX;

void divideTeam(int lv, int end, int sum1, int sum2);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> synergy[i][j];

    divideTeam(0, n, 0, 0);

    cout << ::min << '\n';
    return 0;
}

void divideTeam(int lv, int end, int sum1, int sum2) {
    if(lv == end && team1.size() == end / 2 && team2.size() == end / 2) {
        int result = abs(sum1 - sum2);
        if(::min > result)
            ::min = result;
    } else if(lv < end) {
        int newSum2 = sum2;
        for(auto it = team2.begin(); it != team2.end(); it++)
            newSum2 += synergy[lv][*it] + synergy[*it][lv];
        team2.insert(lv);
        divideTeam(lv + 1, end, sum1, newSum2);
        team2.erase(lv);

        int newSum1 = sum1;
        for(auto it = team1.begin(); it != team1.end(); it++)
            newSum1 += synergy[lv][*it] + synergy[*it][lv];
        team1.insert(lv);
        divideTeam(lv + 1, end, newSum1, sum2);
        team1.erase(lv);
    }
}