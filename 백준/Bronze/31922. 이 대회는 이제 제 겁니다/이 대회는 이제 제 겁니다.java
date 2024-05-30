import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt();
        int p = scanner.nextInt();
        int c = scanner.nextInt();
        
        System.out.println(Math.max(a + c, p));
    }   
}