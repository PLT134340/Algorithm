#include <iostream>
#include <set>
using namespace std;

int synergy[20][20] = {0};
set<int> team;
int min = INT32_MAX;

void divideTeam(int lv, int end);

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> synergy[i][j];

    divideTeam(0, n);

    cout << ::min << '\n';
    return 0;
}

void divideTeam(int lv, int end) {
    if(lv == end && team.size() == end / 2) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < end; i++)
            for(int j = 0; j < end; j++)
                if(team.find(i) != team.end() && team.find(j) != team.end())
                    sum1 += synergy[i][j];
                else if(team.find(i) == team.end() && team.find(j) == team.end())
                    sum2 += synergy[i][j];

        int result = abs(sum1 - sum2);
        if(::min > result)
            ::min = result;
    } else if(lv < end) {
        divideTeam(lv + 1, end);

        team.insert(lv);
        divideTeam(lv + 1, end);
        team.erase(lv);
    }
}