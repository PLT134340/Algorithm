import java.util.*;

class Main {
    
    static int n;
    static int[] pieces;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        pieces = new int[n];
        
        for (int i = 0; i < n; i++)
            pieces[i] = scanner.nextInt();
            
        System.out.println(recurs(0, 0));
    }   
    
    static int recurs(int lv, double sum) {
        if (lv == n) {
            if (sum >= (double)99 / 100 && sum <= (double)101 / 100)
                return 1;
            return 0;
        }
        
        return recurs(lv + 1, sum) + recurs(lv + 1, sum + (double)1 / pieces[lv]);
    }
    
}