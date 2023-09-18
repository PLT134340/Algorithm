#include <string>
#include <vector>

using namespace std;

int arr[1000][1000] = {0};

void snailFill(int length, int depth);

vector<int> solution(int n) {
    snailFill(n, 0);
    
    vector<int> answer;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);
    return answer;
}

void snailFill(int length, int depth) {
    static int num = 1;
    
    int y = 2 * depth;
    int x = depth;
    if(length <= 0)
        return;
    else if(length == 1) {
        arr[y][x] = num;
        return;
    }
    
    for(int i = 0; i < length - 1; i++)
        arr[y++][x] = num++;
    for(int i = 0; i < length - 1; i++)
        arr[y][x++] = num++;
    for(int i = 0; i < length - 1; i++)
        arr[y--][x--] = num++;

    snailFill(length - 3, depth + 1);
}