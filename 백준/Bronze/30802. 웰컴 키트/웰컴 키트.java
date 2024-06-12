import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] size = new int[6];
        for (int i = 0; i < 6; i++)
            size[i] = scanner.nextInt();
        int t = scanner.nextInt();
        int p = scanner.nextInt();
        
        int tCount = 0;
        for (int i = 0; i < 6; i++) {
            tCount += size[i] / t;
            if (size[i] % t != 0)
                tCount++;
        }
        System.out.println(tCount);
        System.out.println(n / p + " " + n % p);
    }   
}