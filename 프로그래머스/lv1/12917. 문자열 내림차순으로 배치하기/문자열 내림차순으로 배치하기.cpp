#include <string>
#include <vector>

using namespace std;

void heapSort(string &s, int start, int end);
void merge(string &s, int start, int end);

string solution(string s) {
    string answer = s;
    heapSort(answer, 0, answer.size());
    return answer;
}

void heapSort(string &s, int start, int end) {
    if(start + 1 == end)
        return;
    
    int mid = (start + end) / 2;
    heapSort(s, start, mid);
    heapSort(s, mid, end);
    merge(s, start, end);
}

void merge(string &s, int start, int end) {
    string newS = "";
    int mid = (start + end) / 2;
    int frontIdx = start;
    int backIdx = mid;
    while(frontIdx < mid && backIdx < end)
        if(s[frontIdx] < s[backIdx])
            newS += string(1, s[backIdx++]);
        else
            newS += string(1, s[frontIdx++]);
    
    if(frontIdx != mid)
        newS += s.substr(frontIdx, mid - frontIdx);
    if(backIdx != end)
        newS += s.substr(backIdx, end - backIdx);
    
    s.replace(start, newS.size(), newS);
}