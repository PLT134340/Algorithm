import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < n; i++)
            sb.append(i * 6 + 3 + " ");
        System.out.println(sb);
    }   
}