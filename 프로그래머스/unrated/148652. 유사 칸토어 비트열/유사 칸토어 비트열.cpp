#include <string>
#include <vector>

using namespace std;

bool check(long long n);

int solution(int n, long long l, long long r) {
    int answer = 0;
    for(long long i = l - 1; i <= r - 1; i++)
        if(check(i))
            answer++;
    
    return answer;
}

bool check(long long n) {
    if(n % 5 == 2)
        return false;
    else if(n >= 5)
        return check(n / 5);
    else
        return true;
}