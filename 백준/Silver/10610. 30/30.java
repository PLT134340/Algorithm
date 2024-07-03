import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String[] num = scanner.next().split("");
        Arrays.sort(num, Collections.reverseOrder());
        
        int sum = 0;
        for (int i = 0; i < num.length; i++)
            sum += Integer.parseInt(num[i]);
        
        if (!(sum % 3 == 0 && num[num.length - 1].equals("0"))) {
            System.out.println(-1);
            return;
        }
        
        for (int i = 0; i < num.length; i++)
            System.out.print(num[i]);
        System.out.println();
    }   
}