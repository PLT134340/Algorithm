import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        String num = br.readLine();

        int[] firstBiggerIdx = new int[n];
        Deque<Pair> deque = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            int digit = num.charAt(i) - '0';

            while (!deque.isEmpty() && digit > deque.peekLast().digit) {
                Pair pair = deque.pollLast();
                firstBiggerIdx[pair.idx] = i;
            }

            deque.offerLast(new Pair(i, digit));
        }
        while (!deque.isEmpty()) {
            Pair pair = deque.pollLast();
            firstBiggerIdx[pair.idx] = -1;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            if (firstBiggerIdx[i] == -1) {
                sb.append(num.charAt(i));
                continue;
            }

            if (firstBiggerIdx[i] - i > k) {
                sb.append(num.charAt(i));
                continue;
            }

            k--;
        }

        sb.setLength(sb.length() - k);
        System.out.println(sb);
    }

    static class Pair {
        public int idx;
        public int digit;

        public Pair(int idx, int digit) {
            this.idx = idx;
            this.digit = digit;
        }
    }
}
