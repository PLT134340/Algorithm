import java.util.*;
import java.io.*;

class Main {
    static Pair[][] root;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        Deque<Pair> dq = new ArrayDeque<>();
        boolean[][] isVisited = new boolean[n][m];
        root = new Pair[n][m];

        char[][] arr = new char[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
                root[i][j] = new Pair(i, j);
                dq.offerLast(new Pair(i, j));
            }
        }

        while (!dq.isEmpty()) {
            Pair p = dq.pollLast();

            if (isVisited[p.y][p.x])
                continue;
            isVisited[p.y][p.x] = true;

            if (arr[p.y][p.x] == 'U') {
                dq.offerLast(new Pair(p.y - 1, p.x));
                union(find(p), find(new Pair(p.y - 1, p.x)));
            } else if (arr[p.y][p.x] == 'D') {
                dq.offerLast(new Pair(p.y + 1, p.x));
                union(find(p), find(new Pair(p.y + 1, p.x)));
            } else if (arr[p.y][p.x] == 'L'){
                dq.offerLast(new Pair(p.y, p.x - 1));
                union(find(p), find(new Pair(p.y, p.x - 1)));
            } else {
                dq.offerLast(new Pair(p.y, p.x + 1));
                union(find(p), find(new Pair(p.y, p.x + 1)));
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (root[i][j].equals(new Pair(i, j)))
                    result++;
        System.out.println(result);
    }

    static void union(Pair p1, Pair p2) {
        root[p2.y][p2.x] = root[p1.y][p1.x];
    }

    static Pair find(Pair p) {
        Pair result = root[p.y][p.x];
        while (!result.equals(root[result.y][result.x]))
            result = root[result.y][result.x];
        return result;
    }

    static class Pair {
        public int y;
        public int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o)
                return true;
            
            Pair pair = (Pair) o;
            if (pair.y == y && pair.x == x)
                return true;
            else
                return false;
        }
    }
}