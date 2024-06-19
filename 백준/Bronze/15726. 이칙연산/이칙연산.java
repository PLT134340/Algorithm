import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        
        if (b > c)
            System.out.println((long)a * b / c);
        else
            System.out.println((long)a * c / b);
    }   
}