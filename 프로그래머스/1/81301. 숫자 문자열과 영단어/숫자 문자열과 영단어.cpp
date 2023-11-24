#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer = "";
    int len = s.length();
    for (int i = 0; i < len;) {
        if (s[i] >= '0' && s[i] <= '9') {
            answer += string(1, s[i++]);
        } else {
            string substr = s.substr(i, 3);
            if (substr == "zer") {
                answer += "0";
                i += 4;
            } else if (substr == "one") {
                answer += "1";
                i += 3;
            } else if (substr == "two") {
                answer += "2";
                i += 3;
            } else if (substr == "thr") {
                answer += "3";
                i += 5;
            } else if (substr == "fou") {
                answer += "4";
                i += 4;
            } else if (substr == "fiv") {
                answer += "5";
                i += 4;
            } else if (substr == "six") {
                answer += "6";
                i += 3;
            } else if (substr == "sev") {
                answer += "7";
                i += 5;
            } else if (substr == "eig") {
                answer += "8";
                i += 5;
            } else {
                answer += "9";
                i += 4;
            }
        }
    }
    return stoi(answer);
}