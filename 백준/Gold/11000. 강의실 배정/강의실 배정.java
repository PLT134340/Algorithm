import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Pair> arrayList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            int s = Integer.parseInt(line[0]);
            int t = Integer.parseInt(line[1]);

            arrayList.add(new Pair(s, t));
        }

        arrayList.sort(
                Comparator.comparing(Pair::getStart)
                        .thenComparing(Pair::getEnd));
                        
        // for (Pair p : arrayList)
        //     System.out.println(p.start + ", " + p.end);
                        
        int result = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (Pair p : arrayList) {
            while (!pq.isEmpty() && pq.peek() <= p.start)
                pq.poll();
            
            pq.offer(p.end);
            
            if (result < pq.size())
                result = pq.size();
        }
        
        System.out.println(result);
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