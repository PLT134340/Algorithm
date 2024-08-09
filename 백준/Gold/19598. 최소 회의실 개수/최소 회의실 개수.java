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
        ArrayList<Pair> arrayList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");

            int start = Integer.parseInt(line[0]);
            int end = Integer.parseInt(line[1]);

            arrayList.add(new Pair(start, end));
        }

        arrayList.sort(Comparator.comparing(Pair::getStart));

        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparing(Pair::getEnd));
        int max = 0;

        for (Pair p : arrayList) {
            while (!pq.isEmpty() && p.getStart() >= pq.peek().getEnd())
                pq.poll();

            pq.offer(p);

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