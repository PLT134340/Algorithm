#include <string>
#include <vector>

using namespace std;

const int INF = 100000000;
int minFare[201][201];

void floyd(int n);

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            minFare[i][j] = INF;
        minFare[i][i] = 0;
    }
    for(auto fare : fares) {
        minFare[fare[0]][fare[1]] = fare[2];
        minFare[fare[1]][fare[0]] = fare[2];
    }
    
    floyd(n);
    
    int answer = INT32_MAX;
    for(int i = 1; i <= n; i++) {
        int result = minFare[s][i] + minFare[i][a] + minFare[i][b];
        if(answer > result)
            answer = result;
    }
    
    return answer;
}

void floyd(int n) {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                int result = minFare[i][k] + minFare[k][j];
                if(minFare[i][j] > result)
                    minFare[i][j] = result;
            }
}