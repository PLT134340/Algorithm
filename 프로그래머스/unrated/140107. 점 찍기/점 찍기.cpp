#include <string>
#include <vector>

using namespace std;

int bound(int n, int d);

long long solution(int k, int d) {
    long long answer = 0;
    for(int i = 0; i * k <= d; i++) {
        int b = bound(i * k, d);
        answer += b / k + 1;
    }
    return answer;
}

int bound(int n, int d) {
    int start = 0;
    int end = d + 1;
    while(start + 1 < end) {
        int mid = (start + end) / 2;
        long long result = (long long)n * n + (long long)mid * mid;
        long long maxNum = (long long)d * d;
        if(result <= maxNum)
            start = mid;
        else
            end = mid;
    }
    return start;
}