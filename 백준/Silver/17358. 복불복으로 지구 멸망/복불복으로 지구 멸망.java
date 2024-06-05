import java.util.*;

class Main {
    static final long MOD = 1_000_000_007L;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); 
        long answer = 1;
        
        for (int i = n - 1; i > 0; i -= 2)
            answer = (answer * i) % MOD;
                
        System.out.println(answer);
    }   
}