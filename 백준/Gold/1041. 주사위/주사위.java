import java.util.Arrays;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        
        int[] num = new int[6];
        for (int i = 0; i < 6; i++)
            num[i] = scanner.nextInt();
        
        if (n == 1) {
            int result = 0;
            int max = 0;
            
            for (int i = 0; i < 6; i++) {
                result += num[i];
                if (max < num[i])
                    max = num[i];
            }
            System.out.println(result - max);
            return;
        }    
        
        int[] three = { 
            num[0] + num[3] + num[4],
            num[0] + num[1] + num[3],
            num[0] + num[2] + num[4],
            num[0] + num[1] + num[2],
            num[5] + num[3] + num[4],
            num[5] + num[1] + num[3],
            num[5] + num[2] + num[4],
            num[5] + num[1] + num[2]
        }; 
        int[] two = {
            num[0] + num[1],
            num[0] + num[2],
            num[0] + num[3],
            num[0] + num[4],
            num[1] + num[2],
            num[1] + num[3],
            num[4] + num[2],
            num[4] + num[3],
            num[5] + num[1],
            num[5] + num[2],
            num[5] + num[3],
            num[5] + num[4],
        }; 
        
        Arrays.sort(three);
        Arrays.sort(two);
        Arrays.sort(num);
        
        long result = three[0] * 4 + two[0] * ((n - 1) * 4 + (n - 2) * 4) + num[0] * ((n - 1) * (n - 2) * 4 + (n - 2) * (n - 2));
        System.out.println(result);
    }   
}