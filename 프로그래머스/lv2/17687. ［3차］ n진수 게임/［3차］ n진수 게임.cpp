#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string num = "0";
    string answer = "";
    for(int i = 0; answer.size() != t;) {
        for(int k = 0; k < num.size() && answer.size() < t; k++, i++)
            if(i % m == p - 1)
                answer += string(1, num[k]);
        
        num.back()++;
        for(int k = num.size() - 1; k > 0; k--)
            if(num[k] == '9' + 1)
                num[k] = 'A';
            else if(num[k] == '0' + n || num[k] == 'A' + n - 10) {
                num[k] = '0';
                num[k - 1]++;
            } else 
                break;
        if(num[0] == '9' + 1)
            num[0] = 'A';
        else if(num[0] == '0' + n || num[0] == 'A' + n - 10) {
            num[0] = '0';
            num = "1" + num;
        }
    }
    
    return answer;
}