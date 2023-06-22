#include <iostream>
using namespace std;

int score[301];
int maxScore[301];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> score[i];
    
    maxScore[1] = score[1];
    maxScore[2] = score[1] + score[2];
    maxScore[3] = max(score[1] + score[3], score[2] + score[3]);
    for(int i = 4; i <= n; i++)
        maxScore[i] = max(maxScore[i - 2] + score[i], maxScore[i - 3] + score[i - 1] + score[i]);
    cout << maxScore[n] << '\n';
    return 0;
}