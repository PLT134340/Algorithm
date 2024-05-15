import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            String str = scanner.next();
            char prevChar = str.charAt(0);
            int[] num = new int[26];
            num[prevChar - 'a']++;
            boolean isGroupWord = true;
            
            for (int j = 1; j < str.length(); j++) {
                char newChar = str.charAt(j);
                
                if (!(prevChar == newChar || num[newChar - 'a'] == 0)) {
                    isGroupWord = false;
                    break;
                }
                
                num[newChar - 'a']++;
                prevChar = newChar;
            }
            
            if (isGroupWord)
                result++;
        }
        
        System.out.println(result);
    }   
}