
import java.util.Scanner;
import java.util.TreeSet;

class Main {
    
    static TreeSet<Long> fib = new TreeSet<>();
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        
        fib.add(1L);
        long sum = 1;
        
        while (sum <= 10_000_000_000_000_000L) {
            long tmp = fib.last();
            fib.add(sum);
            sum += tmp;
        }
        
        for (int i = 0; i < t; i++) {
            int k = scanner.nextInt();
            long x = scanner.nextLong();
            
            if (recurs(k, x))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
    
    static boolean recurs(int count, long target) {
        if (count == 1)
            return fib.contains(target);
            
        boolean result = false;
        for (long num : fib)
            if (num > target)
                break;
            else if (recurs(count - 1, target - num))
                result = true;
        return result;
    }
    
}