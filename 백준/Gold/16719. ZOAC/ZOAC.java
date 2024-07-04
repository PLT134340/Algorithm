import java.util.*;

class Main {
    
    static String[] str;
    static boolean[] isPrinted;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        str = scanner.next().split("");
        isPrinted = new boolean[str.length];
        
        recurs(0, str.length - 1);
    }   
    
    static void recurs(int start, int end) {
        if (start > end)
            return;
        
        int idx = start;
        
        for (int i = start + 1; i <= end; i++)
            if (!isPrinted[i] && str[idx].compareTo(str[i]) >= 1)
                idx = i;
        
        isPrinted[idx] = true;
        print();
        recurs(idx + 1, end);
        recurs(start, idx - 1);
    }
    
    static void print() {
        for (int i = 0; i < str.length; i++)
            if (isPrinted[i])
                System.out.print(str[i]);
        System.out.println();
    }
    
}