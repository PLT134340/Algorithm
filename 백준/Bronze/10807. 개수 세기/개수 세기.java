import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = scanner.nextInt();
        
        int v = scanner.nextInt();
        int result = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] == v)
                result++;
        System.out.println(result);
    }
}