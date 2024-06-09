import java.util.*;

class Main {
    static final int INF = 1000000000;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[][] length = new int[n + 1][n + 1];
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j)
                    length[i][j] = INF;
        
        for (int i = 0; i < k; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            
            length[a][b] = length[b][a] = 1;
        }
                    
        for (int l = 1; l <= n; l++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (length[i][j] > length[i][l] + length[l][j]) 
                        length[i][j] = length[i][l] + length[l][j];
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                if (length[i][j] > 6) {
                    System.out.println("Big World!");
                    return;
                }
        System.out.println("Small World!");
        
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++)
        //         System.out.print(length[i][j] + " ");
        //     System.out.println();
        // }
    }   
}