#include <vector>
#include <iostream>
using namespace std;

bool isNotPrime[3001] = {true, true};

void eratosthenes();
int exeSum(vector<int>& nums);

int solution(vector<int> nums) {
    eratosthenes();
    int answer = exeSum(nums);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    return answer;
}

void eratosthenes() {
    for(int i = 2; i <= 3001; i++)
        if(!isNotPrime[i])
            for(int j = 2; i * j <= 3001; j++)
                isNotPrime[i * j] = true;
}

int exeSum(vector<int>& nums) {
    int result = 0;
    int size = nums.size();
    for(int i = 0; i < size - 2; i++)
        for(int j = i + 1; j < size - 1; j++)
            for(int k = j + 1; k < size; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if(!isNotPrime[sum])
                    result++;
            }
    return result;
}