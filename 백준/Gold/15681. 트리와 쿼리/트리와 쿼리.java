import java.io.*;
import java.util.*;

class Main {
    
    static ArrayList<Set<Integer>> arrayList;
    static int[] numOfNodes;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int r = Integer.parseInt(line[1]);
        int q = Integer.parseInt(line[2]);
        
        arrayList = new ArrayList<>();
        for (int i = 0; i <= n; i++)
            arrayList.add(new HashSet<>());
        numOfNodes = new int[n + 1];
            
        for (int i = 1; i < n; i++) {
            line = br.readLine().split(" ");
            int u = Integer.parseInt(line[0]);
            int v = Integer.parseInt(line[1]);
            
            arrayList.get(u).add(v);
            arrayList.get(v).add(u);
        }
        
        setDirection(r);
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        for (int i = 0; i < q; i++) {
            int root = Integer.parseInt(br.readLine());
            
            bw.write(String.valueOf(numOfNodes[root]));
            bw.newLine();
        }
        bw.flush();
        bw.close();
    }   
    
    static int setDirection(int root) {
        int num = 1;
        for (int nextRoot : arrayList.get(root)) {
            arrayList.get(nextRoot).remove(root);
            num += setDirection(nextRoot);
        }
        numOfNodes[root] = num;
        return num;
    }
    
}