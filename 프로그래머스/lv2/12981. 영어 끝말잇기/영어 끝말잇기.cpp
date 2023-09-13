#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    string prevWord = words[0];
    set<string> s;
    s.insert(prevWord);
    for(int i = 1; i < words.size(); i++)
        if(s.find(words[i]) == s.end() && prevWord.back() == words[i].front()) { 
            prevWord = words[i];
            s.insert(words[i]);
        } else {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    if(answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    cout << answer[0] << ", " << answer[1] << endl;

    return answer;
}