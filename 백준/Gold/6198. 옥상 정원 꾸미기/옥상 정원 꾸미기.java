import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Pair[] pairs = new Pair[n];

        for (int i = 0; i < n; i++) {
            int height = Integer.parseInt(br.readLine());
            pairs[i] = new Pair(i + 1, height);
        }

        Deque<Pair> deque = new ArrayDeque<>();
        long result = 0;

        for (int i = n - 1; i >= 0; i--) {
            while (!deque.isEmpty() && deque.peekLast().height < pairs[i].height)
                deque.pollLast();

            if (deque.isEmpty())
                result += n - pairs[i].order;
            else
                result += deque.peekLast().order - pairs[i].order - 1;

            deque.offerLast(pairs[i]);
        }

        System.out.println(result);
    }

    static class Pair {
        public int order;
        public int height;

        public Pair(int order, int height) {
            this.order = order;
            this.height = height;
        }
    }
}