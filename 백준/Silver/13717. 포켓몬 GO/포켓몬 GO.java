import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        String maxName = "";
        int maxCanEvolve = 0;
        int totalCanEvolve = 0;
        
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            int needToEvolve = scanner.nextInt();
            int candy = scanner.nextInt();
            
            int canEvolve = 0;
            while (candy >= needToEvolve) {
                candy -= needToEvolve;
                candy += 2;
                canEvolve++;
            }
            
            if (maxCanEvolve < canEvolve) {
                maxName = name;
                maxCanEvolve = canEvolve;
            }
            totalCanEvolve += canEvolve;
        }
        
        System.out.println(totalCanEvolve);
        System.out.println(maxName);
    }
}