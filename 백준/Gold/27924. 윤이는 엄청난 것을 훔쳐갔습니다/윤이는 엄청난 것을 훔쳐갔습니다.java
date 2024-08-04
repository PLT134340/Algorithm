import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.Set;
import java.util.TreeSet;

class Main {
    
    static int n;
    static ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++)
            edges.add(new ArrayList<>());
        
        for (int i = 0; i < n - 1; i++) {
            String[] line = br.readLine().split(" ");
            int u = Integer.parseInt(line[0]) - 1;
            int v = Integer.parseInt(line[1]) - 1;
            
            edges.get(u).add(v);
            edges.get(v).add(u);
        }
        
        Set<Integer> leafNodes = new TreeSet<>();
        for (int i = 0; i < n; i++)
            if (edges.get(i).size() == 1)
                leafNodes.add(i);
        
        String[] line = br.readLine().split(" ");
        int a = Integer.parseInt(line[0]) - 1;
        int b = Integer.parseInt(line[1]) - 1;
        int c = Integer.parseInt(line[2]) - 1;
        int[] distanceA = new int[n];
        int[] distanceB = new int[n];
        int[] distanceC = new int[n];
        
        dfs(a, distanceA);
        dfs(b, distanceB);
        dfs(c, distanceC);
        
        boolean canEscape = false;
        for (int leaf : leafNodes)
            if (distanceA[leaf] < distanceB[leaf] && distanceA[leaf] < distanceC[leaf]) {
                canEscape = true;
                break;
            }
            
        if (canEscape)
            System.out.println("YES");
        else
            System.out.println("NO");
            
        // for (int leaf : leafNodes)
        //     System.out.println(String.format("leaf: %d, a: %d, b: %d, c: %d", leaf + 1, distanceA[leaf], distanceB[leaf], distanceC[leaf]));
    }
    
    static void dfs(int start, int[] distance) {
        Deque<Pair> dq = new ArrayDeque<>();
        boolean[] isVisited = new boolean[n];
        
        dq.offerLast(new Pair(0, start));
        isVisited[start] = true;
        
        while (!dq.isEmpty()) {
            Pair now = dq.pollLast();
            
            for (int next : edges.get(now.node))
                if (!isVisited[next]) {
                    dq.offerLast(new Pair(now.lv + 1, next));
                    isVisited[next] = true;
                    distance[next] = now.lv + 1;
                }
        }
    }
    
    static class Pair {
        public int lv;
        public int node;
        
        public Pair(int lv, int node) {
            this.lv = lv;
            this.node = node;
        }
    }
    
}