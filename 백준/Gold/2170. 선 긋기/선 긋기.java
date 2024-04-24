import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bufferedReader.readLine());
        
        Pair[] pairs = new Pair[n];
        for (int i = 0; i < n; i++) {
            String[] strings = bufferedReader.readLine().split(" ");
            int x = Integer.parseInt(strings[0]);
            int y = Integer.parseInt(strings[1]);
            
            pairs[i] = new Pair(x, y);
        }
        
        Arrays.sort(pairs);
        
        int start = pairs[0].getX();
        int end = pairs[0].getY();
        int result = 0;
        
        for (int i = 1; i < n; i++)
            if (pairs[i].getY() <= end)
                continue;
            else if (pairs[i].getX() <= end)
                end = pairs[i].getY();
            else {
                result += end - start;
                start = pairs[i].getX();
                end = pairs[i].getY();
            }
        result += end - start;
        
        System.out.println(result);
    }
}

class Pair implements Comparable<Pair> {
    private int x;
    private int y;
    
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    int getX() {
        return x;
    }
    
    int getY() {
        return y;
    }
    
    @Override
    public int compareTo(Pair target) {
        if (x < target.getX())
            return -1;
        else if (x > target.getX())
            return 1;
        else if (y < target.getY())
            return -1;
        else if (y > target.getY())
            return 1;
        else
            return 0;
    }
}