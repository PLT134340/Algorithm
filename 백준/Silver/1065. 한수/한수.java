import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int result = 0;
        
        for (int i = 1; i <= n; i++) {
            if (i / 100 == 0) {
                result++;
                continue;
            }
            
            int tmp = i;
            ArrayList<Integer> arrayList = new ArrayList<>();
            while (tmp != 0) {
                arrayList.add(tmp % 10);
                tmp /= 10;
            }
            
            int dif = arrayList.get(0) - arrayList.get(1);
            boolean isEqual = true;
            
            for (int j = 2; j < arrayList.size(); j++)
                if (arrayList.get(j - 1) - arrayList.get(j) != dif) {
                    isEqual = false;
                    break;
                }
            
            if (isEqual)
                result++;
        }
        
        System.out.println(result);
    }   
}