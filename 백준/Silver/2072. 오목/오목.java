import java.util.*;

class Main {
    
    static int n;
    static Boolean[][] arr;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        arr = new Boolean[19][19];
        boolean isBlack = true;
        
        for (int i = 0; i < n; i++) {
            int y = scanner.nextInt() - 1;
            int x = scanner.nextInt() - 1;
            
            arr[y][x] = isBlack;
            isBlack = !isBlack;
            
            if (isOver(y, x)) {
                System.out.println(i + 1);
                return;
            }
        }
        
        System.out.println(-1);
    }   
    
    static boolean isOver(int y, int x) {
        int tmpY = y;
        int tmpX = x;
        
        int leftRight = 1;
        while (--tmpX >= 0 && arr[tmpY][tmpX] == arr[y][x])
            leftRight++;
        tmpX = x;
        while (++tmpX < 19 && arr[tmpY][tmpX] == arr[y][x])
            leftRight++;
        tmpX = x;
        
        int upDown = 1;
        while (--tmpY >= 0 && arr[tmpY][tmpX] == arr[y][x])
            upDown++;
        tmpY = y;
        while (++tmpY < 19 && arr[tmpY][tmpX] == arr[y][x])
            upDown++;
        tmpY = y;
        
        int upleftDownright = 1;
        while (--tmpY >= 0 && --tmpX >= 0 &&arr[tmpY][tmpX] == arr[y][x])
            upleftDownright++;
        tmpY = y;
        tmpX = x;
        while (++tmpY < 19 && ++tmpX < 19 && arr[tmpY][tmpX] == arr[y][x])
            upleftDownright++;
        tmpY = y;
        tmpX = x;
        
        int uprightDownleft = 1;
        while (--tmpY >= 0 && ++tmpX < 19 && arr[tmpY][tmpX] == arr[y][x])
            uprightDownleft++;
        tmpY = y;
        tmpX = x;
        while (++tmpY < 19 && --tmpX >= 0 && arr[tmpY][tmpX] == arr[y][x])
            uprightDownleft++;
        tmpY = y;
        tmpX = x;
        
        if (leftRight == 5 || upDown == 5 || upleftDownright == 5 || uprightDownleft == 5)
            return true;
        return false;
    }
}