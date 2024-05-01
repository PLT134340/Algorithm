import java.util.*;

class Main {

    static int[] dy = { 0, 1, 0, -1 };
    static int[] dx = { 1, 0, -1, 0 };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[][] arr = new int[n][n];
        int min = 100;
        int max = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                arr[i][j] = scanner.nextInt();
                if (min > arr[i][j])
                    min = arr[i][j];
                if (max < arr[i][j])
                    max = arr[i][j];
            }

        int result = 0;

        for (int height = min; height <= max; height++) {
            boolean[][] isVisited = new boolean[n][n];
            Deque<Tuple> dq = new ArrayDeque<>();

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (arr[i][j] >= height)
                        dq.offerLast(new Tuple(i, j, 0));

            int num = 0;

            while (!dq.isEmpty()) {
                Tuple p = dq.pollLast();

                if (p.level == 0) {
                    if (isVisited[p.y][p.x])
                        continue;
                        
                    num++;
                    // System.out.println(p.y + ", " + p.x);
                    isVisited[p.y][p.x] = true;
                    
                    // for (int i = 0; i < n; i++) {
                    //     for (int j = 0; j < n; j++)
                    //         System.out.print(isVisited[i][j] + " ");
                    //     System.out.println();
                    // }
                }

                for (int i = 0; i < 4; i++) {
                    int newY = p.y + dy[i];
                    int newX = p.x + dx[i];

                    if (newY >= 0 && newY < n && newX >= 0 && newX < n && arr[newY][newX] >= height
                            && !isVisited[newY][newX]) {
                        dq.offerLast(new Tuple(newY, newX, p.level + 1));
                        isVisited[newY][newX] = true;
                    }
                }
            }

            // System.out.println(height + ": " + num);
            if (result < num)
                result = num;
            
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++)
            //         System.out.print(isVisited[i][j] + " ");
            //     System.out.println();
            // }
        }

        System.out.println(result);
    }

    static class Tuple {
        public int y;
        public int x;
        public int level;

        public Tuple(int y, int x, int level) {
            this.y = y;
            this.x = x;
            this.level = level;
        }
    }
}