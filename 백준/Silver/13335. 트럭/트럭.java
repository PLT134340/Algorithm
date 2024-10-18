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
        int w = Integer.parseInt(line[1]);
        int l = Integer.parseInt(line[2]);

        line = br.readLine().split(" ");
        int[] weights = new int[n];

        for (int i = 0; i < n; i++) {
            weights[i] = Integer.parseInt(line[i]);
        }

        Deque<Pair> deque = new ArrayDeque<>();
        deque.offerLast(new Pair(1, weights[0]));

        int index = 1;
        int now = 0;
        int weightSum = weights[0];

        while (!deque.isEmpty()) {
            now++;

            if (now - deque.peekFirst().startTime >= w) {
                weightSum -= deque.peekFirst().weight;
                deque.pollFirst();
            }

            if (index < n && weightSum + weights[index] <= l) {
                weightSum += weights[index];
                deque.offerLast(new Pair(now, weights[index]));
                index++;
            }
        }

        System.out.println(now);
    }

    static class Pair {
        public int startTime;
        public int weight;

        public Pair(int startTime, int weight) {
            this.startTime = startTime;
            this.weight = weight;
        }
    }
}
