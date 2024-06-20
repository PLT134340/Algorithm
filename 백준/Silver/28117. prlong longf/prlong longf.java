import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        String str = scanner.next();
        
        int[] fib = new int[21];
        fib[0] = fib[1] = 1;
        
        for (int i = 2; i <= 20; i++)   
            fib[i] = fib[i - 1] + fib[i - 2];
        
        int result = 1;
        int count = 0;
        int idx = 0;
        
        for (int i = 0; i < str.length(); i++)
            if (idx == 0 && str.charAt(i) == 'l')
                idx++;
            else if (idx == 1 && str.charAt(i) == 'o')
                idx++;
            else if (idx == 2 && str.charAt(i) == 'n')
                idx++;
            else if (idx == 3 && str.charAt(i) == 'g') {
                count++;
                idx = 0;
            } else {
                result *= fib[count];
                count = 0;
                idx = 0;
                
                if (str.charAt(i) == 'l')
                    idx++;
            } 
        if (count > 0)
            result *= fib[count];
        
        System.out.println(result);
    }   
}