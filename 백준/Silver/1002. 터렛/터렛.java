import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int x1 = scanner.nextInt();
            int y1 = scanner.nextInt();
            int r1 = scanner.nextInt();
            int x2 = scanner.nextInt();
            int y2 = scanner.nextInt();
            int r2 = scanner.nextInt();
            
            if (x1 == x2 && y1 == y2 && r1 == r2) {
                System.out.println(-1);
                continue;
            }
            
            int rSum = r1 + r2;
            int rDif = r1 - r2;
            if (rDif < 0)
                rDif = -rDif;
            
            int xDif = x1 - x2;
            int yDif = y1 - y2;
            int distSquare = xDif * xDif + yDif * yDif;
            
            if (distSquare == rSum * rSum || distSquare == rDif * rDif)
                System.out.println(1);
            else if (distSquare > rDif * rDif && distSquare < rSum * rSum)
                System.out.println(2);
            else
                System.out.println(0);
        }
    }   
}