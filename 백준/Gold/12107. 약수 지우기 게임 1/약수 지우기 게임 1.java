import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        if (n == 1)
            System.out.println("B");
        else
            System.out.println("A");
    }   
}