import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

public class Main {

    static final int[] dy = {0, 1, 0, -1};
    static final int[] dx = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int l = Integer.parseInt(line[1]);
        int r = Integer.parseInt(line[2]);
        int[][] arr = new int[n][n];

        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");

            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(line[j]);
            }
        }

        boolean isBorderOpen = true;
        int count = 0;

        while (isBorderOpen) {
            isBorderOpen = false;

            boolean[][] isVisited = new boolean[n][n];
            Deque<Pair> deque = new ArrayDeque<>();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (isVisited[i][j])
                        continue;

                    Pair start = new Pair(i, j);
                    deque.offerLast(start);
                    isVisited[i][j] = true;
                    ArrayList<Pair> list = new ArrayList<>();
                    list.add(start);

                    while (!deque.isEmpty()) {
                        Pair pair = deque.pollFirst();

                        for (int k = 0; k < 4; k++) {
                            int newY = pair.y + dy[k];
                            int newX = pair.x + dx[k];

                            if (!(newY >= 0 && newY < n && newX >= 0 && newX < n && !isVisited[newY][newX]))
                                continue;

                            int sub = Math.abs(arr[pair.y][pair.x] - arr[newY][newX]);
                            if (!(sub >= l && sub <= r))
                                continue;

                            Pair newPair = new Pair(newY, newX);
                            deque.offerLast(newPair);
                            isVisited[newY][newX] = true;
                            list.add(newPair);
                            isBorderOpen = true;
                        }
                    }

                    int sum = 0;
                    for (Pair pair : list) {
//                        System.out.printf("y=%d x=%d\n", pair.y, pair.x);
                        sum += arr[pair.y][pair.x];
                    }
//                    System.out.println();
                    int div = sum / list.size();

                    for (Pair pair : list) {
                        arr[pair.y][pair.x] = div;
                    }
                }
            }

            if (isBorderOpen) {
                count++;
            }

//            for (int i = 0; i < n; i++) {
//                for (int j = 0; j < n; j++) {
//                    System.out.print(arr[i][j] + " ");
//                }
//                System.out.println();
//            }
        }

        System.out.println(count);
    }

    static class Pair {
        public int y;
        public int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

}