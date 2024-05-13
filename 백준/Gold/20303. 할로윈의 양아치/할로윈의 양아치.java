import java.util.*;
import java.io.*;

class Main {
    
    static int n;
    static int[] root = new int[n];
    static int[] relation = new int[n];
    static int[] candy = new int[n];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        int k = Integer.parseInt(line[2]);
        
        root = new int[n];
        relation = new int[n];
        candy = new int[n];
        
        line = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            root[i] = i;
            relation[i] = 1;
            candy[i] = Integer.parseInt(line[i]);
        }
        
        for (int i = 0; i < m; i++) {
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]) - 1;
            int b = Integer.parseInt(line[1]) - 1;
            
            int aRoot = find(a);
            int bRoot = find(b);
            
            union(aRoot, bRoot);
        }
        
        ArrayList<Node> arrayList = new ArrayList<>();
        for (int i = 0; i < n; i++)
        if (root[i] == i)
        arrayList.add(new Node(relation[i], candy[i]));
        arrayList.sort(Comparator.comparing(Node::getRelation).thenComparing(Node::getCandy));
        
        int[][] dp = new int[arrayList.size() + 1][k];
        for (int i = 1; i <= arrayList.size(); i++) {
            int w = arrayList.get(i - 1).getRelation();
            int v = arrayList.get(i - 1).getCandy();
            for (int j = 1; j < k; j++)
                if (w <= j) {
                    if (v + dp[i - 1][j - w] > dp[i - 1][j])
                        dp[i][j] = v + dp[i - 1][j - w];
                    else
                        dp[i][j] = dp[i - 1][j];
                } else
                    dp[i][j] = dp[i - 1][j];
        }
        
        System.out.println(dp[arrayList.size()][k - 1]);
    }   
    
    static class Node {
        private int relation;
        private int candy;
        
        public Node(int relation, int candy) {
            this.relation = relation;
            this.candy = candy;
        }
        
        public int getRelation() {
            return relation;
        }
        
        public int getCandy() {
            return candy;
        }
    }
    
    static int find(int num) {
        while (num != root[num])
            num = root[num];
        return num;
    }
    
    static void union(int num1, int num2) {
        if (num1 == num2)
            return;
        
        if (candy[num1] > candy[num2]) {
            candy[num1] += candy[num2];
            relation[num1] += relation[num2];
            root[num2] = num1;
        } else {
            candy[num2] += candy[num1];
            relation[num2] += relation[num1];
            root[num1] = num2;
        }
    }
    
}