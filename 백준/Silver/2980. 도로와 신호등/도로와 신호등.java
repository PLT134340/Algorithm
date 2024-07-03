import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int l = scanner.nextInt();
        
        int time = 0;
        int mileage = 0;
        
        for (int i = 0; i < n; i++) {
            int d = scanner.nextInt();
            int r = scanner.nextInt();
            int g = scanner.nextInt();
            
            time += d - mileage;
            mileage = d;
            
            int mod = time % (r + g);
            if (mod < r)
                time += r - mod;
        }
        
        time += l - mileage;
        System.out.println(time );
    }   
}