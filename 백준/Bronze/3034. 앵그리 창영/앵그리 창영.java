import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int w = scanner.nextInt();
        int h = scanner.nextInt();
        
        int diagonal = w * w + h * h;
        
        for (int i = 0; i < n; i++) {
            int length = scanner.nextInt();
            
            if (length * length <= diagonal)
                System.out.println("DA");
            else
                System.out.println("NE");
        }
    }   
}