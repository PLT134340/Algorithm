import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long k = scanner.nextLong();
        
        int count = 0;
        StringBuilder sb = new StringBuilder();
        
        long d = 2;
        while (k > 1 && d <= (int)Math.sqrt(k) + 1) {
            if (k % d != 0) {
                d++;
                continue;
            }
            
            k /= d;
            count++;
            sb.append(d + " ");
        }
        
        if (k > 1) {
            count++;
            sb.append(k);
        }
        
        System.out.println(count);
        System.out.println(sb);
    }   
}