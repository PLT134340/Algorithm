import java.io.*;

class Main {
    
    static int n;
    static Pair[] pairs;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());
        pairs = new Pair[n];

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            int x = Integer.parseInt(line[0]);
            int y = Integer.parseInt(line[1]);
            
            pairs[i] = new Pair(x, y);
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int q = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < q; i++) {
            double k = Double.parseDouble(br.readLine());
            
            int left = binarySearch(k);
            int leftY = pairs[left].y;
            int rightY = pairs[left + 1].y;
            // System.out.println(k + " " + left + " " + (left + 1));
            
            if (leftY < rightY)
                bw.write(String.valueOf(1));
            else if (leftY > rightY)
                bw.write(String.valueOf(-1));
            else
                bw.write(String.valueOf(0));
            bw.newLine();
        }
        
        bw.flush();
        bw.close();
    }   
    
    static int binarySearch(double x) {
        int start = 0;
        int end = n - 1;
        
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (pairs[mid].x > x)
                end = mid;
            else
                start = mid;
        }
        
        return start;
    }
    
    static class Pair {
        public int x;
        public int y;
        
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}