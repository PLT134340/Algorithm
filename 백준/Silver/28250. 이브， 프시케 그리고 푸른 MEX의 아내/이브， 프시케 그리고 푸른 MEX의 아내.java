import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        int[] arr = new int[3];
        for (int i = 0; i < n; i++) {
            int tmp = scanner.nextInt();
            if (tmp == 0)
                arr[0]++;
            else if (tmp == 1)
                arr[1]++;
            else
                arr[2]++;
        }
            
        long result = 0;
        result += (long)arr[0] * (arr[0] - 1) / 2;
        result += (long)arr[0] * arr[1] * 2;
        result += (long)arr[0] * arr[2];
        System.out.println(result);
    }
}