import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int q = Integer.parseInt(line[1]);

        Tuple[] arr = new Tuple[q];

        for (int i = 0; i < q; i++) {
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]) - 1;
            int b = Integer.parseInt(line[1]) - 1;
            int x = Integer.parseInt(line[2]);

            arr[i] = new Tuple(a, b, x, i);
        }

        Arrays.sort(arr, Comparator.comparing(Tuple::getStart)
                .thenComparing(Tuple::getOrder));
        PriorityQueue<Tuple> pq = new PriorityQueue<>(Comparator.comparing(Tuple::getOrder));

        StringBuilder sb = new StringBuilder();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            while (idx < q && arr[idx].getStart() == i) {
                pq.offer(arr[idx]);
                idx++;
            }

            if (pq.isEmpty())
                sb.append(0).append(" ");
            else
                sb.append(pq.peek().color).append(" ");

            while (!pq.isEmpty() && pq.peek().getEnd() <= i) {
                pq.poll();
            }
        }

        System.out.println(sb);
    }

    static class Tuple {
        private int start;
        private int end;
        private int color;
        private int order;

        public Tuple(int start, int end, int color, int order) {
            this.start = start;
            this.end = end;
            this.color = color;
            this.order = order;
        }

        public int getStart() {
            return start;
        }

        public int getEnd() {
            return end;
        }

        public int getColor() {
            return color;
        }

        public int getOrder() {
            return order;
        }
    }
}