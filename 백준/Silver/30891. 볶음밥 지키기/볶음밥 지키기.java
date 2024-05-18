import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int r = scanner.nextInt();
        
        Pair[] pairs = new Pair[n];
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            pairs[i] = new Pair(x, y);
        }
        
        int max = 0;
        Pair pair = pairs[0];
        
        for (int i = -100; i <= 100; i++)
            for (int j = -100; j <= 100; j++) {
                int num = 0;
                for (int k = 0; k < n; k++) {
                    int dy = pairs[k].y - i;
                    int dx = pairs[k].x - j;
                    
                    if (dy * dy + dx * dx <= r * r)
                        num++;
                }
                
                if (max < num) {
                    max = num;
                    pair = new Pair(j, i);
                }
            }
                
        System.out.println(pair.x + " " + pair.y);
    }   
    
    static class Pair {
        public int x;
        public int y;
        
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}