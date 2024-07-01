import java.util.*;

class Main {
    
    static int n;
    static int[] nums;
    static Set<Long> set = new HashSet<>();
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        nums = new int[n];
        
        for (int i = 0; i < n; i++)
            nums[i] = scanner.nextInt();
        
        recurs(0, 0);
        
        long sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        
        System.out.println(sum - set.size() + 1);
    }   
    
    static void recurs(int lv, long sum) {
        if (lv == n) {
            set.add(sum);
            return;
        }
        
        recurs(lv + 1, sum);
        recurs(lv + 1, sum + nums[lv]);
    }
}