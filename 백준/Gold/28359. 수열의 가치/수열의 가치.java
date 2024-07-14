import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] nums = new int[1001];
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            nums[num]++;
            sum += num;
        }
        
        int max = 0;
        int maxNum = 0;
        for (int i = 1; i <= 1000; i++) {
            int mul = i * nums[i];
            if (max < mul) {
                max = mul;
                maxNum = i;
            }
        }
        
        System.out.println(sum + max);
        for (int i = 1; i < maxNum; i++)
            for (int j = 0; j < nums[i]; j++)
                System.out.print(i + " ");
        for (int i = 1000; i > maxNum; i--)
            for (int j = 0; j < nums[i]; j++)
                System.out.print(i + " ");
        for (int i = 0; i < nums[maxNum]; i++)
            System.out.print(maxNum + " ");
    }   
}