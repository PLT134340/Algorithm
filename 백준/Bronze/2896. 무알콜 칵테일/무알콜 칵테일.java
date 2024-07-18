import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[] amount = new int[3];
        int[] ratio = new int[3];
        
        for (int i = 0; i < 3; i++)
            amount[i] = scanner.nextInt();
        for (int i = 0; i < 3; i++)
            ratio[i] = scanner.nextInt();
                
        double min = 500;
        for (int i = 0; i < 3; i++) {
            double div = (double)amount[i] / ratio[i];
            if (min > div)
                min = div;
        }
        
        for (int i = 0; i < 3; i++) {
            System.out.print(amount[i] - ratio[i] * min + " ");
        }
    }   
}