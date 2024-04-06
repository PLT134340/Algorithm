import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        
        double grade;
        if (s.charAt(0) == 'A')
            grade = 4.0;
        else if (s.charAt(0) == 'B')
            grade = 3.0;
        else if (s.charAt(0) == 'C')
            grade = 2.0;
        else if (s.charAt(0) == 'D')
            grade = 1.0;
        else {
            System.out.println("0.0");
            return;
        }
        
        if (s.charAt(1) == '+')
            grade += 0.3;
        else if (s.charAt(1) == '-')
            grade -= 0.3;

        System.out.println(grade);        
    }
}