#include <vector>

using namespace std;

vector<int> quadTree(vector<vector<int>> &arr, pair<int, int> start, int size);

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = quadTree(arr, {0, 0}, arr.size());
    return answer;
}

vector<int> quadTree(vector<vector<int>> &arr, pair<int, int> start, int size) {
    if(size == 1) {
        vector<int> v;
        v.push_back(!arr[start.first][start.second]);
        v.push_back(arr[start.first][start.second]);
        return v;
    }
    
    bool isZero;
    bool isOne;
    if(arr[start.first][start.second]) {
        isZero = false;
        isOne = true;
    } else {
        isZero = true;
        isOne = false;
    }
    
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(isZero && isOne)
                break;
            else if(isZero && arr[start.first + i][start.second + j] == 1)
                isOne = true;
            else if(isOne && arr[start.first + i][start.second + j] == 0)
                isZero = true;
    
    int zero = 0;
    int one = 0;
    vector<vector<int>> results(4);
    if(isZero && isOne) {
        results[0] = quadTree(arr, start, size / 2);
        results[1] = quadTree(arr, {start.first, start.second + size / 2}, size / 2);
        results[2] = quadTree(arr, {start.first + size / 2, start.second}, size / 2);
        results[3] = quadTree(arr, {start.first + size / 2, start.second + size / 2}, size / 2);
        for(int i = 0; i < 4; i++) {
            zero += results[i][0];
            one += results[i][1];
        }
    } else if(isZero) {
        zero = 1;
        one = 0;
    } else {
        zero = 0;
        one = 1;
    }
    
    vector<int> result;
    result.push_back(zero);
    result.push_back(one);
    return result;
}

