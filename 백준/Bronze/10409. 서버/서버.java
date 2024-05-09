import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int t = scanner.nextInt();
        
        int sum = 0;
        int count = 0;
        while (count < n) {
            int time = scanner.nextInt();
            sum += time;
            
            if (sum <= t)
                count++;
            else
                break;
        }
        
        System.out.println(count);
    }   
}