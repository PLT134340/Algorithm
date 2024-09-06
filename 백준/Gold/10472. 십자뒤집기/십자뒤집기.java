import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

class Main {

    static int[] dy = {0, 0, -1, 0, 1};
    static int[] dx = {0, -1, 0, 1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int p = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < p; i++) {
            boolean[][] end = new boolean[3][3];

            for (int j = 0; j < 3; j++) {
                String line = br.readLine();
                for (int k = 0; k < 3; k++)
                    end[j][k] = line.charAt(k) == '*';
            }

            int endBit = toBit(end);

            int[] minDepth = new int[512];
            Arrays.fill(minDepth, Integer.MAX_VALUE);
            minDepth[0] = 0;

            Deque<Pair> deque = new ArrayDeque<>();
            deque.offerLast(new Pair(0, 0));

            while (!deque.isEmpty()) {
                Pair pair = deque.pollFirst();

                if (pair.bit == endBit) {
                    sb.append(pair.lv).append("\n");
                    break;
                }

                boolean[][] array = toArray(pair.bit);
//                System.out.println(pair.lv + " " + pair.bit);
//                for (int j = 0; j < 3; j++) {
//                    for (int k = 0; k < 3; k++) {
//                        if (array[j][k])
//                            System.out.print("*");
//                        else
//                            System.out.print(".");
//                    }
//                    System.out.println();
//                }

                for (int j = 0; j < 3; j++)
                    for (int k = 0; k < 3; k++) {
                        boolean[][] newArray = new boolean[3][3];
                        for (int l = 0; l < 3; l++)
                            for (int m = 0; m < 3; m++)
                                newArray[l][m] = array[l][m];

                        for (int l = 0; l < 5; l++) {
                            int newY = j + dy[l];
                            int newX = k + dx[l];

                            if (newY >= 0 && newY < 3 && newX >= 0 && newX < 3)
                                 newArray[newY][newX] = !newArray[newY][newX];
                        }

                        int newBit = toBit(newArray);
                        int newLv = pair.lv + 1;

                        if (minDepth[newBit] <= newLv)
                            continue;

                        deque.offerLast(new Pair(newLv, newBit));
                        minDepth[newBit] = newLv;
                    }
            }
        }

        System.out.print(sb);
    }

    static boolean[][] toArray(int bit) {
        boolean[][] result = new boolean[3][3];

        for (int i = 2; i >= 0; i--)
            for (int j = 2; j >= 0; j--) {
                result[i][j] = bit % 2 == 1;
                bit /= 2;
            }

        return result;
    }

    static int toBit(boolean[][] array) {
        int result = 0;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                result <<= 1;
                if (array[i][j])
                    result += 1;
            }

        return result;
    }

    static class Pair {
        public int lv;
        public int bit;

        public Pair(int lv, int bit) {
            this.lv = lv;
            this.bit = bit;
        }
    }
}