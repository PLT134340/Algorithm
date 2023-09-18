#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int> pq;
    int size = score.size();
    
    for(int i = 0; i < size; i++) {
        pq.push(score[i]);
        
        vector<int> v;
        for(int j = 0; !pq.empty() && j < k; j++) {
            v.push_back(pq.top());
            pq.pop();
        }
        
        answer.push_back(v.back());
        
        for(auto it = v.begin(); it != v.end(); it++)
            pq.push(*it);
    }
    
    return answer;
}