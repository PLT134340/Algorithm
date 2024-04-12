import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        Integer[] arr1 =  Arrays.stream(queue1).boxed().toArray(Integer[]::new);
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(arr1));
        Integer[] arr2 =  Arrays.stream(queue2).boxed().toArray(Integer[]::new);
        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(arr2));

        int queue1Size = queue1.length;
        int queue2Size = queue2.length;
        
        long sum1 = 0;
        for (int i = 0; i < queue1Size; i++)
            sum1 += queue1[i];
        long sum2 = 0;
        for (int i = 0; i < queue2Size; i++)
            sum2 += queue2[i];
        
        int totalSize = queue1Size + queue2Size;
        int count1 = 0;
        int count2 = 0;
        
        while (count1 < totalSize && count2 < totalSize)
            if (sum1 > sum2) {
                int tmp = q1.poll();
                q2.offer(tmp);
                
                sum1 -= tmp;
                sum2 += tmp;
                count1++;
            } else if (sum1 < sum2) {
                int tmp = q2.poll();
                q1.offer(tmp);
                
                sum2 -= tmp;
                sum1 += tmp;
                count2++;
            } else 
                return count1 + count2;
        
        return -1;
    }
}