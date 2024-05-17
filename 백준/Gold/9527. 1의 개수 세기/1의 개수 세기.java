import java.util.*;

class Main {
    
    static ArrayList<Long> arrayList = new ArrayList<>();
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        
        long sum = 0;
        long i = 1;
        
        while (i <= 10_000_000_000_000_000L) {
            arrayList.add(sum);
            sum = sum * 2 + i * 2 - i;
            i *= 2;
        }
        
        long aNum = recurs(a);
        long bNum = recurs(b + 1);
        
        System.out.println(bNum - aNum);
    }   
    
    static long recurs(long n) {
        if (n == 0)
            return 0;
        
        int i = 0;
        long tmp = 1;
        while (tmp <= n) {
            tmp *= 2;
            i++;
        }
        tmp /= 2;
        i--;
        
        return arrayList.get(i) + n - tmp + recurs(n - tmp);
    }
}