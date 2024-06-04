import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        ArrayList<Long> arrayList = new ArrayList<>();
        Deque<Long> dq = new ArrayDeque<>();
        for (long i = 0; i < 10; i++) {
            arrayList.add(i);
            dq.offerLast(i);
        }
        
        while (!dq.isEmpty()) {
            long num = dq.pollLast();
            
            int mod = (int)(num % 10);
            if (mod == 0)
                continue;
                
            for (int i = 0; i < mod; i++) {
                if (num * 10 + i < 0) {
                    System.out.println(num);
                }
                arrayList.add(num * 10 + i);
                dq.offerLast(num * 10 + i);
            }
        }
        
        Collections.sort(arrayList);
        if (arrayList.size() <= n)
            System.out.println(-1);
        else
            System.out.println(arrayList.get(n));
    }   
}