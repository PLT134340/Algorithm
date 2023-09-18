#include <string>
#include <vector>
using namespace std;

bool arr[100][100] = {false};

int solution(vector<vector<int>> board) {
    int n = board.size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 1)
                for(int k = -1; k <= 1; k++)
                    for(int l = -1; l <= 1; l++) {
                        int newY = i + k;
                        int newX = j + l;
                        if(newY >= 0 && newY < n && newX >= 0 && newX < n)
                            arr[newY][newX] = true;
                    }
    
    int answer = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(!arr[i][j])
                answer++;
    return answer;
}