import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        long[] difficulty = new long[n];
        line = br.readLine().split(" ");

        for (int i = 0; i < n; i++)
            difficulty[i] = Integer.parseInt(line[i]);

        int p = Integer.parseInt(br.readLine());
        ArrayList<ArrayList<Pair>> tips = new ArrayList<>();
        for (int i = 0; i < n; i++)
            tips.add(new ArrayList<>());

        for (int i = 0; i < p; i++) {
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]) - 1;
            int b = Integer.parseInt(line[1]) - 1;
            int t = Integer.parseInt(line[2]);

            difficulty[b] += t;
            tips.get(a).add(new Pair(b, t));
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparing(Pair::getSecond));
        boolean[] isClear = new boolean[n];
        int clearCount = 0;
        long max = 0;

        for (int i = 0; i < n; i++)
            pq.offer(new Pair(i, difficulty[i]));

        while (!pq.isEmpty() && clearCount < m) {
            Pair pair = pq.poll();

            if (isClear[pair.getFirst()])
                continue;

            isClear[pair.getFirst()] = true;
            clearCount++;
            if (max < pair.getSecond())
                max = pair.getSecond();
//            System.out.printf("%d: %d\n", pair.getFirst() + 1, pair.getSecond());

            for (Pair extra : tips.get(pair.getFirst())) {
                difficulty[extra.getFirst()] -= extra.getSecond();
                pq.offer(new Pair(extra.getFirst(), difficulty[extra.getFirst()]));
            }
        }

        System.out.println(max);
    }

    static class Pair {
        private int first;
        private long second;

        public Pair(int first, long second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() {
            return first;
        }

        public long getSecond() {
            return second;
        }
    }
}