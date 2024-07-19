import java.util.*;

class Main {
    
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();

        int[][] matrix = new int[n][n];
        ArrayList<Node> arrayList = new ArrayList<>();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
                if (matrix[i][j] != 0)
                    arrayList.add(new Node(i, j, matrix[i][j], 0));
            }
            
        arrayList.sort(Comparator.comparing(Node::getNum));
        int s = scanner.nextInt();
        int y = scanner.nextInt();
        int x = scanner.nextInt();

        Deque<Node> dq = new ArrayDeque<>();
        for (Node node : arrayList)
            dq.offer(node);
            
        while (!dq.isEmpty()) {
            Node node = dq.poll();
            
            if (node.lv >= s)
                continue;
            
            for (int i = 0; i < 4; i++) {
                int newY = node.y + dy[i];
                int newX = node.x + dx[i];
                
                if (newY >= 0 && newY < n && newX >= 0 && newX < n && matrix[newY][newX] == 0) {
                    matrix[newY][newX] = node.num;
                    dq.offer(new Node(newY, newX, node.num, node.lv + 1));
                }
            }
        }
        
        // System.out.println();
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         System.out.print(matrix[i][j] + " ");
        //     System.out.println();
        // }
        // System.out.println();
        
        
        System.out.println(matrix[y - 1][x - 1]);
    }

    static class Node {
        public int y;
        public int x;
        public int num;
        public int lv;

        public Node(int y, int x, int num, int lv) {
            this.y = y;
            this.x = x;
            this.num = num;
            this.lv = lv;
        }
        
        public int getNum() {
            return num;
        }
    }
}