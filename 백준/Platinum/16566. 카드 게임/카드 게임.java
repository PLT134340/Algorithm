import java.io.*;

class Main {
    static int[] arr;
    static int[] disjoint;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        int k = Integer.parseInt(line[2]);
        
        line = br.readLine().split(" ");
        boolean[] isAvailable = new boolean[n + 1];
        
        for (int i = 0; i < m; i++) { 
            int num = Integer.parseInt(line[i]);
            isAvailable[num] = true;
        }
        
        arr = new int[m];
        for (int i = 0, j = 1; i < m; j++)
            if (isAvailable[j])
                arr[i++] = j;
                
        disjoint = new int[m + 1];
        for (int i = 0; i <= m; i++)
            disjoint[i] = i;
        line = br.readLine().split(" ");
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
                
        for (int i = 0; i < k; i++) {
            int num = Integer.parseInt(line[i]);
            int idx = find(upperBound(num));
            
            bw.write(String.valueOf(arr[idx]));
            bw.newLine();
            
            union(idx, idx + 1);
        }
        
        bw.flush();
        bw.close();
    }   
    
    static int upperBound(int val) {
        int start = 0;
        int end = arr.length - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] > val)
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return start;
    }
    
    static void union(int a, int b) { 
        int aRoot = find(a);
        int bRoot = find(b);
        
        if (aRoot == bRoot)
            return;
        
        disjoint[a] = bRoot;
    }
    
    static int find(int n) {
        while (n != disjoint[n])
            n = disjoint[n];
        return n;
    }
}