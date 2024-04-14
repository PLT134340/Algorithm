import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        String t = scanner.next();

        StringBuilder sb = new StringBuilder(t);
        boolean isReverse = false;
        while (sb.length() > s.length()) {
            if (isReverse) {
                if (sb.charAt(0) == 'B')
                    isReverse = false;
                sb.deleteCharAt(0);
            } else {
                if (sb.charAt(sb.length() - 1) == 'B')
                    isReverse = true;
                sb.deleteCharAt(sb.length() - 1);
            }
        }
        
        String result;
        if (isReverse) {
            result = sb.reverse().toString();
        } else
            result = sb.toString();
        
        
        if (s.equals(result))
            System.out.println(1);
        else
            System.out.println(0);
    }
}