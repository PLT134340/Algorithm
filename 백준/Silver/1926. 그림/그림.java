import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        boolean[][] isFilled = new boolean[n][m];
        Deque<Pairs> deque = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");

            for (int j = 0; j < m; j++) {
                isFilled[i][j] = line[j].equals("1");
                if (isFilled[i][j]) {
                    Pair pair = new Pair(i, j);
                    deque.offerLast(new Pairs(pair, pair));
                }
            }
        }

        boolean[][] isVisited = new boolean[n][m];
        Map<Pair, Integer> map = new HashMap<>();

        while (!deque.isEmpty()) {
            Pairs pairs = deque.pollLast();
            Pair now = pairs.now;

            if (isVisited[now.y][now.x])
                continue;

            isVisited[now.y][now.x] = true;
            map.merge(pairs.start, 1, Integer::sum);

            for (int i = 0; i < 4; i++) {
                int newY = now.y + dy[i];
                int newX = now.x + dx[i];

                if (newY >= 0 && newY < n && newX >= 0 && newX < m
                        && isFilled[newY][newX] && !isVisited[newY][newX]) {
                    deque.offerLast(new Pairs(pairs.start, new Pair(newY, newX)));
                }
            }
        }

        System.out.println(map.size());

        int max = 0;
        for (int count : map.values())
            if (max < count)
                max = count;
        System.out.println(max);
    }

    static class Pair {
        public int y;
        public int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public boolean equals(Object object) {
            if (this == object) return true;
            if (object == null || getClass() != object.getClass()) return false;
            Pair pair = (Pair) object;
            return y == pair.y && x == pair.x;
        }

        @Override
        public int hashCode() {
            return Objects.hash(y, x);
        }
    }

    static class Pairs {
        public Pair start;
        public Pair now;

        public Pairs(Pair start, Pair now) {
            this.start = start;
            this.now = now;
        }
    }
}
