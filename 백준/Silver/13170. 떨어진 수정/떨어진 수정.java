import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int p = scanner.nextInt();
        int w = scanner.nextInt();
        
        int result = p / w;
        if (p % w > 0)
            result++;
        System.out.println(result);
    }   
}