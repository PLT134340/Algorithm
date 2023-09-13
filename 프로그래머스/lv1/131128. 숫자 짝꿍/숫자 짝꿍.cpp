#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    int numX[10] = {0};
    int numY[10] = {0};
    for(int i = 0; i < X.size(); i++)
        numX[X[i] - '0']++;
    for(int i = 0; i < Y.size(); i++)
        numY[Y[i] - '0']++;
    
    int common[10] = {0};
    for(int i = 0; i < 10; i++)
        common[i] = min(numX[i], numY[i]);
    
    string answer = "";
    for(int i = 9; i >= 1; i--)
        answer += string(common[i], '0' + i);
    
    if(!answer.empty())
        answer += string(common[0], '0');
    else if(common[0] > 0)
        answer = "0";
    else
        answer = "-1";
    return answer;
}