import java.io.*;
import java.util.*;

class Main {
    
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        
        int[][] matrix = new int[n][m];
        Node start = new Node(0, 0, 0);
        
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                matrix[i][j] = (int)(str.charAt(j) - '0');
                if (matrix[i][j] == 2)
                start = new Node(i, j, 0);
            }
        }
        
        Deque<Node> dq = new ArrayDeque<>();
        boolean[][] isVisited = new boolean[n][m];
        dq.offer(start);
        isVisited[start.y][start.x] = true;
        
        while (!dq.isEmpty()) {
            Node nd = dq.poll();
            
            if (matrix[nd.y][nd.x] == 3 || matrix[nd.y][nd.x] == 4 || matrix[nd.y][nd.x] == 5) {
                System.out.println("TAK");
                System.out.println(nd.lv);
                return;
            }
            
            for (int i = 0; i < 4; i++) {
                int newY = nd.y + dy[i];
                int newX = nd.x + dx[i];
                
                if (newY >= 0 && newY < n && newX >= 0 && newX < m && !isVisited[newY][newX] && matrix[newY][newX] != 1) {
                    isVisited[newY][newX] = true;
                    dq.offer(new Node(newY, newX, nd.lv + 1));
                }
            }
        }
        
        System.out.println("NIE");
    }   
    
    static class Node {
        public int y;
        public int x;
        public int lv;
        
        public Node(int y, int x, int lv) {
            this.y = y;
            this.x = x;
            this.lv = lv;
        }
    }
}