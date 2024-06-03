import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        
        String[] line = br.readLine().split(" ");
        int heights[] = new int[n];
        for (int i = 0; i < n; i++)
            heights[i] = Integer.parseInt(line[i]);

        int[] result = new int[n];
        Deque<Node> dq = new ArrayDeque<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!dq.isEmpty() && heights[i] > dq.peekLast().num) {
                Node nd = dq.pollLast();
                result[nd.idx] = i + 1;
            }
            dq.offerLast(new Node(i, heights[i]));
        }

        for (int i = 0; i < n; i++)
            bw.write(String.valueOf(result[i]) + " ");
        bw.newLine();
        bw.flush();
        bw.close();
    }
    
    static class Node {
        public int idx;
        public int num;
    
        public Node(int idx, int num) {
            this.idx = idx;
            this.num = num;
        }
    }    
}
