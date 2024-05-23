import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int[] nums = new int[line.length];
        
        for (int i = 0; i < line.length; i++)
            nums[i] = Integer.parseInt(line[i]);
        
        line = br.readLine().split(" ");
        int x = Integer.parseInt(line[0]);
        
        for (int i = 0; i < nums.length; i++)
            if (nums[i] == x) {
                System.out.println(i + 1);
                return;
            }
        
        System.out.println(0);
    }   
}