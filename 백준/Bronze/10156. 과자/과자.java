import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int k = scanner.nextInt();
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        int dif = k * n - m;
        if (dif < 0)
            dif = 0;
        System.out.println(dif);
    }   
}