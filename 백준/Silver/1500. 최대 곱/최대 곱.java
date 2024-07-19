import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int s = scanner.nextInt();
        int k = scanner.nextInt();
        
        int quotient = s / k;
        int remainder = s % k;
        long answer = 1;
        
        for (int i = 0; i < k - remainder; i++)
            answer *= quotient;
        for (int i = 0; i < remainder; i++)
            answer *= (quotient + 1);
            
        System.out.println(answer);
    }   
}