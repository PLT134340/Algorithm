import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int l = scanner.nextInt();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            int length = scanner.nextInt();
            sum += length;
        }
        
        if (sum > m)
            System.out.println(-1);
        else if (sum == m)
            System.out.println(0);
        else if (sum >= l || sum + l <= m)
            System.out.println(1);
        else
            System.out.println(-1);
    }
}