#include <string>
#include <vector>
#include <queue>

using namespace std;

int prioritySize[10] = {0};

int solution(vector<int> priorities, int location) {
    int vSize = priorities.size();
    int firstOutSize = 0;
    for(int i = 0; i < vSize; i++)
        prioritySize[priorities[i]]++;
    
    queue<pair<int, int>> q;
    for(int i = 0; i < vSize; i++)
        q.push({i, priorities[i]});
    
    int answer = 0;
    int target = priorities[location];
    for(int i = 9; i > target; i--)
        while(prioritySize[i] > 0) {
            if(q.front().second == i) {
                q.pop();
                prioritySize[i]--;
                answer++;
            } else {
                q.push(q.front());
                q.pop();
            }
        }
    while(q.front().first != location)
        if(q.front().second < target) {
            q.push(q.front());
            q.pop();
        } else {
            q.pop();
            answer++;
        }
    answer++;
    
    return answer;
}