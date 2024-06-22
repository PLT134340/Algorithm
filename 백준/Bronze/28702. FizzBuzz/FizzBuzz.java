import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String[] str = new String[3];
        for (int i = 0; i < 3; i++)
            str[i] = scanner.next();
        
        int n = 0;
        for (int i = 0; i < 3; i++)
            if (str[i].equals("Fizz"))
                continue;
            else if (str[i].equals("Buzz"))
                continue;
            else if (str[i].equals("FizzBuzz"))
                continue;
            else
                n = Integer.parseInt(str[i]) + 3 - i;
                
        if (n % 3 == 0 && n % 5 == 0)
            System.out.println("FizzBuzz");
        else if (n % 3 == 0)
            System.out.println("Fizz");
        else if (n % 5 == 0)
            System.out.println("Buzz");
        else
            System.out.println(n);
    }   
}