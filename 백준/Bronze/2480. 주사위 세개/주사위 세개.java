import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n1 = scanner.nextInt();
        int n2 = scanner.nextInt();
        int n3 = scanner.nextInt();
        
        int result;
        if (n1 == n2 && n2 == n3)
            result = 10000 + n1 * 1000;
        else if (n1 == n2 || n1 == n3)
            result = 1000 + n1 * 100;
        else if (n2 == n3)
            result = 1000 + n2 * 100;
        else
            result = Math.max(Math.max(n1, n2), n3) * 100;
            
        System.out.println(result);
    }   
}