import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            String[] line = br.readLine().split(" ");
            int m = Integer.parseInt(line[0]);
            int n = Integer.parseInt(line[1]);

            Node[] nodes = new Node[n];
            for (int j = 0; j < n; j++)
                nodes[j] = new Node(j);
            boolean isPossible = true;

            for (int j = 0; j < m; j++) {
                line = br.readLine().split(" ");
                int h1 = Integer.parseInt(line[0]);
                int h2 = Integer.parseInt(line[1]);

                if (isPossible && !union(h1, h2, nodes))
                    isPossible = false;
            }

            if (isPossible)
                sb.append("successful hashing\n");
            else
                sb.append("rehash necessary\n");
        }

        System.out.print(sb);
    }

    static boolean union(int v1, int v2, Node[] nodes) {
        Node rootNode1 = find(v1, nodes);
        Node rootNode2 = find(v2, nodes);

        if (rootNode1 == rootNode2)
            rootNode1.size++;
        else {
            rootNode2.parent = rootNode1.idx;
            rootNode1.set.addAll(rootNode2.set);
            rootNode1.size += rootNode2.size + 1;
        }

        return rootNode1.size <= rootNode1.set.size();
    }

    static Node find(int v, Node[] nodes) {
        Node node = nodes[v];
        while (node.parent != node.idx)
            node = nodes[node.parent];
        return node;
    }

    static class Node {
        public int idx;
        public int size;
        public int parent;
        public Set<Integer> set = new HashSet<>();

        public Node(int idx) {
            this.idx = idx;
            this.size = 0;
            this.parent = idx;
            set.add(idx);
        }
    }
}