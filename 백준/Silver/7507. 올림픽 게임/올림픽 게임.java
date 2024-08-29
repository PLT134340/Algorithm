import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            int m = Integer.parseInt(br.readLine());
            PriorityQueue<Match> pq = new PriorityQueue<>(
                    Comparator.comparing(Match::getDay)
                            .thenComparing(Match::getEnd));

            for (int j = 0; j < m; j++) {
                String[] line = br.readLine().split(" ");
                int d = Integer.parseInt(line[0]);
                int s = Integer.parseInt(line[1]);
                int e = Integer.parseInt(line[2]);

                pq.offer(new Match(d, s, e));
            }

            int count = 0;
            int prevDay = 0;
            int prevEnd = 0;

            while (!pq.isEmpty()) {
                Match match = pq.poll();

                if (match.getDay() <= prevDay && match.getStart() < prevEnd)
                    continue;

                count++;
                prevDay = match.getDay();
                prevEnd = match.getEnd();
            }

            sb.append("Scenario #").append(i + 1).append(":\n");
            sb.append(count).append("\n\n");
        }

        System.out.print(sb);
    }

    static class Match {
        private int day;
        private int start;
        private int end;

        public Match(int day, int start, int end) {
            this.day = day;
            this.start = start;
            this.end = end;
        }

        public int getDay() {
            return day;
        }

        public int getStart() {
            return start;
        }

        public int getEnd() {
            return end;
        }
    }
}