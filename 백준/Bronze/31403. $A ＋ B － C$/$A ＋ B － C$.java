import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String a = scanner.next();
        String b = scanner.next();
        int c = scanner.nextInt();
        
        System.out.println(Integer.parseInt(a) + Integer.parseInt(b) - c);
        int result = Integer.parseInt(a + b) - c;
        System.out.println(result);
    }   
}