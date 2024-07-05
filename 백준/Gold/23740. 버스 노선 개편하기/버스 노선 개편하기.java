import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Node> arrayList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            int s = Integer.parseInt(line[0]);
            int e = Integer.parseInt(line[1]);
            int c = Integer.parseInt(line[2]);

            arrayList.add(new Node(s, e, c));
        }

        arrayList.sort(
                Comparator.comparing(Node::getStart)
                        .thenComparing(Node::getEnd)
                        .thenComparing(Node::getCost));
                        
        int start = arrayList.get(0).getStart();
        int end = arrayList.get(0).getEnd();
        int cost = arrayList.get(0).getCost();
        ArrayList<Node> result = new ArrayList<>();
        
        for (int i = 1; i < n; i++) {
            Node nd = arrayList.get(i);
            
            if (nd.getStart() > end) {
                result.add(new Node(start, end, cost));
                start = nd.getStart();
                end = nd.getEnd();
                cost = nd.getCost();
                continue;
            }
            
            if (end < nd.getEnd())
                end = nd.getEnd();
            if (cost > nd.getCost())
                cost = nd.getCost();
        }
        result.add(new Node(start, end, cost));

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(String.valueOf(result.size()));
        bw.newLine();

        for (Node nd : result) {
            bw.write(nd.start + " " + nd.end + " " + nd.cost);
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }

    static class Node {
        int start;
        int end;
        int cost;

        public Node(int start, int end, int cost) {
            this.start = start;
            this.end = end;
            this.cost = cost;
        }

        public Node compose(Node n) {
            int start = Math.min(this.start, n.getStart());
            int end = Math.max(this.end, n.getEnd());
            int cost = Math.min(this.cost, n.getCost());

            return new Node(start, end, cost);
        }

        public int getStart() {
            return start;
        }

        public int getEnd() {
            return end;
        }

        public int getCost() {
            return cost;
        }
    }
}