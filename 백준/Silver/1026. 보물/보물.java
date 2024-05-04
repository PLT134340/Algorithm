import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = scanner.nextInt();
            
        int[] b = new int[n];
        for (int i = 0; i < n; i++)
            b[i] = scanner.nextInt();
        
        Arrays.sort(a);
        Arrays.sort(b);
        
        int result = 0;
        for (int i = 0; i < n; i++)
            result += b[n - i - 1] * a[i];
        System.out.println(result);
    }   
}