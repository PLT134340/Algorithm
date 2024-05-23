import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            String str = scanner.next();
            int n = Integer.parseInt(str);
            int square = n * n;
            
            int mod = 1;
            for (int j = 0; j < str.length(); j++)
                mod *= 10;
            
            if (square % mod == n)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }   
}