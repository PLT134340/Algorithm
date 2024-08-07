
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String str = scanner.next();
        int result = 1;
        int charCount = 0;
        int decimalCount = 0;

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == 'c') {
                if (decimalCount > 0) {
                    int mul = 10;
                    for (int j = 1; j < decimalCount; j++)
                        mul *= 9;
                    result *= mul;
                    decimalCount = 0;
                }
                charCount++;
            } else {
                if (charCount > 0) {
                    int mul = 26;
                    for (int j = 1; j < charCount; j++)
                        mul *= 25;
                    result *= mul;
                    charCount = 0;
                }
                decimalCount++;
            }
        }
        
        if (decimalCount > 0) {
            int mul = 10;
            for (int j = 1; j < decimalCount; j++)
                mul *= 9;
            result *= mul;
        }
        
        if (charCount > 0) {
            int mul = 26;
            for (int j = 1; j < charCount; j++)
                mul *= 25;
            result *= mul;
        }
        
        System.out.println(result);
    }
}