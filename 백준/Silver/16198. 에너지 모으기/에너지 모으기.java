
import java.util.Scanner;

class Main {
    
    static int n;
    static int[] arr;
    static boolean [] isRemoved;
    static int max = 0;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        arr = new int[n];
        
        for (int i = 0; i < n; i++)
            arr[i] = scanner.nextInt();
        
        isRemoved = new boolean[n];
        
        recurs(n, 0);
        
        System.out.println(max);
    }
    
    static void recurs(int size, int sum) {
        if (size == 2) {
            if (max < sum)
                max = sum;
            return;
        }
        
        for (int i = 1; i < n - 1; i++)
            if (!isRemoved[i]) {
                int left = i - 1;
                while (isRemoved[left])
                    left--;
                int right = i + 1;
                while (isRemoved[right])
                    right++;
                
                isRemoved[i] = true;
                recurs(size - 1, sum + arr[left] * arr[right]);
                isRemoved[i] = false;
            }
    }
    
}