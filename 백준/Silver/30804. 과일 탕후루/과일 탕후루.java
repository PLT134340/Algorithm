import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[] s = new int[n];
        
        String[] line = br.readLine().split(" ");
        for (int i = 0; i < n; i++)
            s[i] = Integer.parseInt(line[i]);
        
        int[] num = new int[10];
        int type = 0;
        int left = 0;
        int max = 0;
        
        for (int right = 0; right < n; right++) {
            if (num[s[right]] == 0) {
                while (type >= 2) {
                    num[s[left]]--;
                    if (num[s[left]] == 0)
                        type--;
                    left++;
                }
                type++;
            } 
            num[s[right]]++;
            
            if (max < right - left + 1)
                max = right - left + 1;
        }
        
        System.out.println(max);
    }   
}