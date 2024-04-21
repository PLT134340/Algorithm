import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        int tmp = b;
        for (int i = 0; i < 3; i++) {
            System.out.println(a * (tmp % 10));
            tmp /= 10;
        }
        System.out.println(a * b);
    }
}