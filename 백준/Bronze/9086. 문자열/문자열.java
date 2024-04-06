import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        
        for (int i = 0; i < t; i++) {
            String s = scanner.next();
            StringBuilder sb = new StringBuilder();
            sb.append(s.charAt(0));
            sb.append(s.charAt(s.length() - 1));
            System.out.println(sb.toString());
        }
    }
}