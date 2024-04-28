import java.util.*;

class Main {
    static int m, n;
    static int[][] arr;
    static boolean[][] isVisited;
    static int[] dy = {0, -1, 0, 1};
    static int[] dx = {-1, 0, 1, 0};
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        m = scanner.nextInt();
        n = scanner.nextInt();
        int k = scanner.nextInt();
        
        arr = new int[m][n];
        for (int i = 0; i < k; i++) {
            int x1 = scanner.nextInt();
            int y1 = scanner.nextInt();
            int x2 = scanner.nextInt();
            int y2 = scanner.nextInt();
            
            if (x1 > x2) {
                int tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
            if (y1 > y2) {
                int tmp = y1;
                y1 = y2;
                y2 = tmp;
            }
            
            x2--;
            y2--;
            
            for (int j = y1; j <= y2; j++)
                for (int l = x1; l <= x2; l++)
                    arr[j][l]++;
        }
        
        isVisited = new boolean[m][n];
        ArrayList<Integer> arrayList = new ArrayList<>();
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (arr[i][j] == 0) {
                    int num = recurse(i, j, 0);
                    if (num > 0)
                        arrayList.add(num);
                }
        
        arrayList.sort(Comparator.naturalOrder());
        System.out.println(arrayList.size());
        for (int l : arrayList)
            System.out.print(l + " ");
    }
    
    public static int recurse(int y, int x, int lv) {
        if (isVisited[y][x])
            return lv;
        isVisited[y][x] = true;
            
        lv++;
        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            
            if (newY >= 0 && newY < m && newX >= 0 && newX < n && arr[newY][newX] == 0 && !isVisited[newY][newX])
                lv += recurse(newY, newX, 0);
        }
        return lv;
    }
}