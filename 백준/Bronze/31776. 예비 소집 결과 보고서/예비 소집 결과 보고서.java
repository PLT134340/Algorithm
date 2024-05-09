import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            int[] arr = new int[3];
            for (int j = 0; j < 3; j++)
                arr[j] = scanner.nextInt();
            
            if (arr[0] == -1)
                continue;
            
            if (arr[1] == -1 && arr[2] == -1)
                count++;
            else if (arr[2] == -1 && arr[0] <= arr[1])
                count++;
            else if (arr[0] <= arr[1] && arr[1] <= arr[2])
                count++;
        }
        
        System.out.println(count);
    }   
}