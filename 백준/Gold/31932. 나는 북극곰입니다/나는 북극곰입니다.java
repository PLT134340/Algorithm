import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        ArrayList<ArrayList<Edge>> edges = new ArrayList<>();
        for (int i = 0; i < n; i++)
            edges.add(new ArrayList<>());

        for (int i = 0; i < m; i++) {
            line = br.readLine().split(" ");
            int u = Integer.parseInt(line[0]) - 1;
            int v = Integer.parseInt(line[1]) - 1;
            int d = Integer.parseInt(line[2]);
            int t = Integer.parseInt(line[3]);
            
            edges.get(u).add(new Edge(v, d, t));
            edges.get(v).add(new Edge(u, d, t));
        }

        PriorityQueue<Node> pq = new PriorityQueue<>(
                Comparator.comparing(nd -> nd.timeLimit, Comparator.reverseOrder()));
        int[] maxLimit = new int[n];
        Arrays.fill(maxLimit, -1);
        
        for (Edge e : edges.get(n - 1)) {
            int timeLimit = e.timeLimit - e.distance;
            pq.offer(new Node(e.to, timeLimit));
            maxLimit[n - 1] = Math.max(maxLimit[n - 1], e.timeLimit);
            maxLimit[e.to] = timeLimit;
        }

        while (!pq.isEmpty()) {
            Node now = pq.poll();

            if (maxLimit[now.to] > now.timeLimit)
                continue;
            maxLimit[now.to] = now.timeLimit;

            if (now.to == 0) {
                System.out.println(maxLimit[0]);
                return;
            }

            for (Edge e : edges.get(now.to)) {
                int nextLimit = Math.min(now.timeLimit, e.timeLimit) - e.distance;
                if (maxLimit[e.to] >= nextLimit)
                    continue;
                maxLimit[e.to] = nextLimit;

                pq.offer(new Node(e.to, nextLimit));
            }
        }

        System.out.println(-1);
    }

    static class Edge {
        public int to;
        public int distance;
        public int timeLimit;

        public Edge(int to, int distance, int timeLimit) {
            this.to = to;
            this.distance = distance;
            this.timeLimit = timeLimit;
        }
    }

    static class Node {
        public int to;
        public int timeLimit;

        public Node(int to, int timeLimit) {
            this.to = to;
            this.timeLimit = timeLimit;
        }
    }
}