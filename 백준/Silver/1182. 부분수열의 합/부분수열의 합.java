import java.util.*;

class Main {
    
    static int s;
    static int[] arr;
    static int count = 0;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        s = scanner.nextInt();
        
        arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = scanner.nextInt();
            
        recurs(0, 0, false);
        
        System.out.println(count);
    }   
    
    static void recurs(int level, int sum, boolean isSizeNonZero) {
        if (level == arr.length) {
            if (isSizeNonZero && sum == s)
                count++;
            return;
        }
        
        recurs(level + 1, sum + arr[level], true);
        recurs(level + 1, sum, isSizeNonZero);
    }
}