import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (i + 2 < str.length() && str.charAt(i) == 'd' && str.charAt(i + 1) == 'z' && str.charAt(i + 2) == '=')
                i += 2;
            else if (i + 1 < str.length() && str.charAt(i) == 'c' && str.charAt(i + 1) == '=')
                i++;
            else if (i + 1 < str.length() && str.charAt(i) == 'c' && str.charAt(i + 1) == '-')
                i++;
            else if (i + 1 < str.length() && str.charAt(i) == 'd' && str.charAt(i + 1) == '-')
                i++;
            else if (i + 1 < str.length() && str.charAt(i) == 'l' && str.charAt(i + 1) == 'j')
                i++;
            else if (i + 1 < str.length() && str.charAt(i) == 'n' && str.charAt(i + 1) == 'j')
                i++;
            else if (i + 1 < str.length() && str.charAt(i) == 's' && str.charAt(i + 1) == '=')
                i++;
            else if (i + 1 < str.length() && str.charAt(i) == 'z' && str.charAt(i + 1) == '=')
                i++;
            count++;
        }   
        
        System.out.println(count);
    }   
}