import java.util.*;

class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        
        int answer = 0;
        int num = 0;
        
        for (int i = 0; i < citations.length; i++) {
            if (num < citations[i] && num <= citations.length - i) {
                answer = num++;
                i--;
            } else if (num == citations[i] && citations[i] <= citations.length - i)
                answer = num;
        }   
        return answer;
    }
}