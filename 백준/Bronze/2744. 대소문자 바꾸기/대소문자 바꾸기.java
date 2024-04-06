import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++)
            if (Character.isUpperCase(s.charAt(i)))
                sb.append(Character.toLowerCase(s.charAt(i)));
            else
                sb.append(Character.toUpperCase(s.charAt(i)));
                
        System.out.println(sb.toString());
    }
}