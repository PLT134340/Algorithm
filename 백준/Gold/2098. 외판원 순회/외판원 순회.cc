#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int INF = 100000000;

int n;
int w[17][17];
int dp[17][65535];
set<int> mask;

void maskRecurs(int size);
void next();
unsigned short getBit(set<int> &s);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
            if (w[i][j] == 0)
                w[i][j] = INF;
        }
        w[i][i] = 0;
    }

    for (int i = 2; i <= n; i++)
        dp[i][0] = w[1][i];

    for (int i = 1; i <= n - 2; i++) // 집합 크기 1 ~ n - 2(1, 마지막 제외)
        maskRecurs(i);

    mask.clear();
    for (int i = 2; i <= n; i++)
        mask.insert(i);
    auto bit = getBit(mask);

    auto s = mask;
    int minSum = INT32_MAX;
    for (auto it = mask.begin(); it != mask.end(); it++) {
        s.erase(*it);
        int sum = dp[*it][getBit(s)] + w[*it][1];
        if (minSum > sum)
            minSum = sum;
        s.insert(*it);
    }
    dp[1][bit] = minSum;

    cout << dp[1][bit] << '\n';
    return 0;
}

void maskRecurs(int size) {
    if (size == mask.size())
        next();

    for (int i = mask.empty() ? 2 : *mask.rbegin() + 1; i <= 16; i++) {
        mask.insert(i);
        maskRecurs(size);
    }

    if (!mask.empty())
        mask.erase(*mask.rbegin());
}

void next() {
    unsigned short bit = getBit(mask);
    for (int i = 2; i <= 16; i++)
        if (mask.find(i) == mask.end()) {
            int minSum = INT32_MAX;
            auto s = mask;
            for (auto it = mask.begin(); it != mask.end(); it++) {
                s.erase(*it);
                int sum = dp[*it][getBit(s)] + w[*it][i];
                if (minSum > sum)
                    minSum = sum;
                s.insert(*it);
            }
            dp[i][bit] = minSum;
        }
}

unsigned short getBit(set<int> &s) {
    unsigned short result = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        unsigned short tmp = 1;
        tmp <<= *it - 1;
        result ^= tmp;
    }
    return result;
}