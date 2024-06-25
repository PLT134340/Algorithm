import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int t = Integer.parseInt(line[1]);
        
        line = br.readLine().split(" ");
        int[] seq = new int[line.length];
        for (int i = 0; i < seq.length; i++)
            seq[i] = Integer.parseInt(line[i]) - 1;
        
        
        Manager manager = new Manager(n);
        ArrayList<Integer> result = new ArrayList<>();
        
        int i = 0;
        while (result.size() < t) {
            line = br.readLine().split(" ");
            
            int id = manager.act(seq[i++], line);
            // System.out.println(id);
            result.add(id);
            
            while (result.size() < t && id != Integer.parseInt(line[0])) {
                id = manager.act(seq[i++], line);
                // System.out.println(id);
                result.add(id);
            }
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int val : result) {
            bw.write(String.valueOf(val));
            bw.newLine();
        }
        bw.flush();
        bw.close();
    }   
    
    static class User {
        private Set<Integer> resource;
        
        public User() {
            resource = new HashSet<>();
        }
        
        public void acquire(int n) {
            resource.add(n);
        }
        
        public void release(int n) {
            resource.remove(n);
        }
    }
    
    static class Manager {
        private User[] users;
        private int[][] queue;
        private Set<Integer> usingResource;
        
        public Manager(int n) {
            users = new User[n];
            for (int i = 0; i < n; i++)
                users[i] = new User();
            queue = new int[n][2];
            usingResource = new HashSet<>();
        }
        
        public int act(int seq, String[] line) {
            if (queue[seq][0] != 0) {
                int id = queue[seq][0];
                if (acquire(seq, queue[seq][0], queue[seq][1]))
                    queue[seq][0] = 0;
                return id;
            }
            
            int id = Integer.parseInt(line[0]);
            
            if (line[1].equals("next"))
                return id;   
            else if (line[1].equals("release")) {
                int n = Integer.parseInt(line[2]);
                users[seq].release(n);
                usingResource.remove(n);
                return id;
            }
            
            int n = Integer.parseInt(line[2]);
            acquire(seq, id, n);
            return id;
        }
        
        private boolean acquire(int seq, int id, int n) {
            if (usingResource.contains(n)) {
                queue[seq][0] = id;
                queue[seq][1] = n;
                return false;
            }
                
            users[seq].acquire(n);
            usingResource.add(n);
            return true;
        }
    }
    
}