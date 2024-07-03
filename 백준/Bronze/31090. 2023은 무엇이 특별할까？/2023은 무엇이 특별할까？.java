import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            
            if ((n + 1) % (n % 100) == 0)
                System.out.println("Good");
            else
                System.out.println("Bye");
        }
    }   
}