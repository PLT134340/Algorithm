import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int y = scanner.nextInt();
        int x = scanner.nextInt();
        int k = scanner.nextInt();

        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = scanner.nextInt();
        
        int[] nums = new int[6];
        int top = 0;
        int front = 1;
        int right = 2;
        
        int[] dy = {0, 0, -1, 1};
        int[] dx = {1, -1, 0, 0};
        
        ArrayList<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < k; i++) {
            int move = scanner.nextInt() - 1;
            int newY = y + dy[move];
            int newX = x + dx[move];
            
            if (newY == -1 || newY == n)
                continue;
            if (newX == -1 || newX == m)
                continue;
            
            y = newY;
            x = newX;
            
            int tmp = top;
            if (move == 0) {
                top = 5 - right;
                right = tmp;
            } else if (move == 1) {
                top = right;
                right = 5 - tmp;
            } else if (move == 2) {
                top = 5 - front;
                front = tmp;
            } else {
                top = front;
                front = 5 - tmp;
            }
            
            if (arr[y][x] == 0)
                arr[y][x] = nums[5 - top];
            else {
                nums[5 - top] = arr[y][x];
                arr[y][x] = 0;
            }
            
            result.add(nums[top]);
        }
        
        for (int i = 0; i < result.size(); i++)
            System.out.println(result.get(i));
    }
}