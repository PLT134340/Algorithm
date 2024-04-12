import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Pair[] leftDays = new Pair[progresses.length];
        
        for (int i = 0; i < leftDays.length; i++) {
            int val = (100 - progresses[i]) / speeds[i];
            if ((100 - progresses[i]) % speeds[i] != 0)
                val++;
            leftDays[i] = new Pair(i, val);
        }
        
        Arrays.sort(leftDays, Comparator.comparing(Pair::getVal)
                    .thenComparing(Pair::getIdx, Comparator.reverseOrder()));
            
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        ArrayList<Integer> list = new ArrayList<>();
        int idx = 0;
        
        for (int i = 0; i < leftDays.length; i++) {
            if (idx < leftDays[i].getIdx())
                pq.offer(leftDays[i].getIdx());
            else if (idx == leftDays[i].getIdx()) {
                int num = 1;
                
                while (!pq.isEmpty() && pq.peek() == idx + 1) {
                    pq.poll();
                    num++;
                    idx++;
                }
                
                idx++;
                list.add(num);
            }
        }
        
        int[] answer = new int[list.size()];
        for (int i = 0; i < answer.length; i++)
            answer[i] = list.get(i);
        return answer;
    }
}

class Pair {
    private int idx;
    private int val;
    
    public Pair(int idx, int val) {
        this.idx = idx;
        this.val = val;
    }
    
    int getIdx() {
        return idx;
    }
    
    int getVal() {
        return val;
    }
}