import java.util.*;
import java.io.*;

class Main {

    static int[][] matrix;
    static ArrayList<Pair> virus = new ArrayList<>();
    static ArrayList<Pair> blank = new ArrayList<>();
    static ArrayList<Integer> activeVirus = new ArrayList<>();

    static int[] dy = { 0, 1, 0, -1 };
    static int[] dx = { 1, 0, -1, 0 };
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                matrix[i][j] = Integer.parseInt(line[j]);
                if (matrix[i][j] == 2)
                    virus.add(new Pair(i, j));
                else if (matrix[i][j] == 0)
                    blank.add(new Pair(i, j));
            }
        }

        recurs(0, m);

        if (min == Integer.MAX_VALUE)
            System.out.println(-1);
        else
            System.out.println(min);
    }

    static void recurs(int level, int m) {
        if (activeVirus.size() == m) {
            dfs();
            return;
        } else if (level == virus.size())
            return;

        activeVirus.add(level);
        recurs(level + 1, m);
        activeVirus.remove(activeVirus.size() - 1);
        recurs(level + 1, m);
    }

    static void dfs() {
        int n = matrix.length;
        Deque<Node> q = new ArrayDeque<>();
        int blankNum = blank.size();
        int[][] isVisited = new int[n][n];

        for (int idx : activeVirus) {
            Pair p = virus.get(idx);
            isVisited[p.y][p.x] = 0;
            q.offer(new Node(0, p));
        }

        int result = 0;

        while (!q.isEmpty()) {
            Node node = q.poll();

            if (blankNum == 0)
                break;

            for (int i = 0; i < 4; i++) {
                int newY = node.pair.y + dy[i];
                int newX = node.pair.x + dx[i];

                if (newY >= 0 && newY < n && newX >= 0 && newX < n && matrix[newY][newX] != 1
                        && isVisited[newY][newX] == 0) {
                    Pair newP = new Pair(newY, newX);
                    
                    if (matrix[newY][newX] == 0)
                        blankNum--;
                    result = node.level + 1;
                    
                    isVisited[newY][newX] = node.level + 1;
                    q.offer(new Node(node.level + 1, newP));
                }
            }
        }

        // System.out.println(result);
        // for (int i = 0; i < activeVirus.size(); i++)
        //     System.out.print(virus.get(activeVirus.get(i)) + " ");
        // System.out.println();

        // System.out.println(result);

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         System.out.print(isVisited[i][j] + " ");
        //     System.out.println();
        // }
        // System.out.println();
        
        if (blankNum == 0 && min > result)
            min = result;
    }

    static class Pair {
        public int y;
        public int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public String toString() {
            return String.format("(%d, %d)", y, x);
        }
    }

    static class Node {
        public int level;
        public Pair pair;

        public Node(int level, Pair pair) {
            this.level = level;
            this.pair = pair;
        }
    }
}
