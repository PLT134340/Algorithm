import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Pair> pairs = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            int h = Integer.parseInt(line[0]);
            int o = Integer.parseInt(line[1]);

            if (h > o) {
                int tmp = o;
                o = h;
                h = tmp;
            }

            pairs.add(new Pair(h, o));
        }

        int d = Integer.parseInt(br.readLine());
        pairs.sort(Comparator.comparing(Pair::getEnd));
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparing(Pair::getStart));
        int max = 0;

        for (Pair p : pairs) {
            while (!pq.isEmpty() && pq.peek().getStart() < p.getEnd() - d)
                pq.poll();

            if (p.getEnd() - p.getStart() <= d)
                pq.add(p);

            if (max < pq.size())
                max = pq.size();
        }

        System.out.println(max);
    }

    static class Pair {
        int start;
        int end;

        public Pair(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int getStart() {
            return start;
        }

        public int getEnd() {
            return end;
        }
    }
}