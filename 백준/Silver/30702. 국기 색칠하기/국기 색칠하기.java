import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

class Main {

    static int[] dy = {0, 0, 1, -1};
    static int[] dx = {1, -1, 0, 0};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        char[][] original = new char[n][m];
        char[][] target = new char[n][m];

        for (int i = 0; i < n; i++) {
            String str = scanner.next();
            for (int j = 0; j < m; j++)
                original[i][j] = str.charAt(j);
        }

        for (int i = 0; i < n; i++) {
            String str = scanner.next();
            for (int j = 0; j < m; j++)
                target[i][j] = str.charAt(j);
        }

        Character[][] copy = new Character[n][m];
        Deque<Tuple> deque = new ArrayDeque<>();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                deque.offerLast(new Tuple(i, j, target[i][j]));

        while (!deque.isEmpty()) {
            Tuple p = deque.pollLast();

            if (copy[p.y][p.x] != null)
                continue;
            copy[p.y][p.x] = p.color;

            for (int i = 0; i < 4; i++) {
                int newY = p.y + dy[i];
                int newX = p.x + dx[i];

                if (newY < 0 || newY >= n || newX < 0 || newX >= m
                        || copy[newY][newX] != null || original[p.y][p.x] != original[newY][newX])
                    continue;

                deque.offerLast(new Tuple(newY, newX, p.color));
            }
        }

        boolean isEqual = true;
        for (int i = 0; i < n && isEqual; i++)
            for (int j = 0; j < m; j++)
                if (target[i][j] != copy[i][j]) {
                    isEqual = false;
                    break;
                }

        if (isEqual)
            System.out.println("YES");
        else
            System.out.println("NO");
    }

    static class Tuple {
        public int y;
        public int x;
        public char color;

        public Tuple(int y, int x, char color) {
            this.y = y;
            this.x = x;
            this.color = color;
        }
    }

}