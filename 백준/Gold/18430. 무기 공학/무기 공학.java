import java.util.*;

class Main {

    static final int dy[][] = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
    static final int dx[][] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    static int n, m;
    static int[][] arr;
    static boolean[][] isVisited;

    static int max = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        m = scanner.nextInt();
        arr = new int[n][m];
        isVisited = new boolean[n][m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = scanner.nextInt();


        recurs(0, 0);
                
        System.out.println(max);
    }
    
    static class Pair {
        public int y;
        public int x;
        
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static void recurs(int num, int sum) {
        if (num == n * m) {
            if (max < sum)
                max = sum;
            return;
        }

        int y = num / m;
        int x = num % m;

        recurs(num + 1, sum);
        
        for (int i = 0; i < 4; i++) {
            Pair edge1 = new Pair(y + dy[i][0], x + dx[i][0]);
            Pair edge2 = new Pair(y + dy[i][1], x + dx[i][1]);

            if (edge1.y < 0 || edge1.y >= n || edge2.y < 0 || edge2.y >= n ||
                    edge1.x < 0 || edge1.x >= m || edge2.x < 0 || edge2.x >= m ||
                    isVisited[y][x] || isVisited[edge1.y][edge1.x] || isVisited[edge2.y][edge2.x])
                continue;

            isVisited[y][x] = isVisited[edge1.y][edge1.x] = isVisited[edge2.y][edge2.x] = true;
            int newSum = sum + arr[y][x] * 2 + arr[edge1.y][edge1.x] + arr[edge2.y][edge2.x];
            recurs(num + 1, newSum);
            isVisited[y][x] = isVisited[edge1.y][edge1.x] = isVisited[edge2.y][edge2.x] = false;
        }
    }

}