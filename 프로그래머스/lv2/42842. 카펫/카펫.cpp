#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int y, x;
    for(int i = 1; i * i <= yellow; i++) {
        y = i;
        x = yellow / y;
        if(y * x == yellow && (y + 2) * (x + 2) == brown + yellow)
            break;
    }
    
    vector<int> answer;
    answer.push_back(x + 2);
    answer.push_back(y + 2);
    return answer;
}