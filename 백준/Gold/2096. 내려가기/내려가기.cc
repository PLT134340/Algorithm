#include <iostream>
using namespace std;

int minScore[2][3] = {0};
int maxScore[2][3] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) {
            int tmp;
            cin >> tmp;

            if (j == 0) {
                minScore[i % 2][j] = min(minScore[(i - 1) % 2][0], minScore[(i - 1) % 2][1]) + tmp;
                maxScore[i % 2][j] = max(maxScore[(i - 1) % 2][0], maxScore[(i - 1) % 2][1]) + tmp;
            } else if (j == 1) {
                minScore[i % 2][j] = min(min(minScore[(i - 1) % 2][0], minScore[(i - 1) % 2][1]), minScore[(i - 1) % 2][2]) + tmp;
                maxScore[i % 2][j] = max(max(maxScore[(i - 1) % 2][0], maxScore[(i - 1) % 2][1]), maxScore[(i - 1) % 2][2]) + tmp;
            } else {
                minScore[i % 2][j] = min(minScore[(i - 1) % 2][1], minScore[(i - 1) % 2][2]) + tmp;
                maxScore[i % 2][j] = max(maxScore[(i - 1) % 2][1], maxScore[(i - 1) % 2][2]) + tmp;
            }
        }
    
    cout << max(max(maxScore[(n - 1) % 2][0], maxScore[(n - 1) % 2][1]), maxScore[(n - 1) % 2][2]) << ' ' << min(min(minScore[(n - 1) % 2][0], minScore[(n - 1) % 2][1]), minScore[(n - 1) % 2][2]) << '\n';
    return 0;
}
