import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int x_a = scanner.nextInt();
        int y_a = scanner.nextInt();
        int x_b = scanner.nextInt();
        int y_b = scanner.nextInt();
        
        long result = (long)(n + 1) * n * (n + 1) * n / 4;
        if (x_a == x_b) {
            int max = (int)Math.floor(Math.max(y_a, y_b) + 0.5);
            int min = (int)Math.ceil(Math.min(y_a, y_b) + 0.5);
            if (max > n)
                max = n;
            if (min < 0)
                min = 0;
            
            long y = max - min;
            if (y <= 0) {
                System.out.println(result);
                return;
            }
            
            result += (y + 1) * y * (n + 1) / 2;
        } else if (y_a == y_b) {
            int max = (int)Math.floor(Math.max(x_a, x_b) + 0.5);
            int min = (int)Math.ceil(Math.min(x_a, x_b) + 0.5);
            if (max > n)
                max = n;
            if (min < 0)
                min = 0;
            
            long x = max - min;
            if (x <= 0) {
                System.out.println(result);
                return;
            }
            
            result += (x + 1) * x * (n + 1) / 2;
        }
        System.out.println(result);
    }
}