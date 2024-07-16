import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] nums = new int[n];
        
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        
        int m = scanner.nextInt();
        Edge[] edges = new Edge[m];
        
        for (int i = 0; i < m; i++) {
            int src = scanner.nextInt() - 1;
            int dest = scanner.nextInt() - 1;
            int cost = scanner.nextInt();
            
            edges[i] = new Edge(src, dest, cost);
        }
        
        Map<Integer, Integer> map = new HashMap<>();
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(0, nums));
        
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            
            if (map.containsKey(Arrays.hashCode(p.arr))) {
                continue;
            }
            map.put(Arrays.hashCode(p.arr), p.cost);
            
            // System.out.print(String.format("cost: %d, arr: ", p.cost));
            // for (int i = 0; i < p.arr.length; i++) {
            //     System.out.print(p.arr[i] + " ");
            // }
            // System.out.println();
            
            for (int i = 0; i < m; i++) {
                Edge e = edges[i];

                int[] newArr = p.arr.clone();
                int newCost = p.cost + e.cost;
                swap(newArr, e.v1, e.v2);
                
                if (!map.containsKey(Arrays.hashCode(newArr)) || map.get(Arrays.hashCode(newArr)) > newCost) {
                    pq.add(new Pair(newCost, newArr));
                }
            }
        }
        
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);
        
        if (map.containsKey(Arrays.hashCode(sortedNums))) {
            System.out.println(map.get(Arrays.hashCode(sortedNums)));
        } else {
            System.out.println(-1);
        }
        
    }   
    
    static void swap(int[] arr, int idx1, int idx2) {
        int tmp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = tmp;
    }
    
    static class Edge {
        public int v1;
        public int v2;
        public int cost;
        
        public Edge(int v1, int v2, int cost) {
            this.v1 = v1;
            this.v2 = v2;
            this.cost = cost;
        }
    }
    
    static class Pair implements Comparable<Pair> {
        int cost;
        int[] arr;
        
        public Pair(int cost, int[] arr) {
            this.cost = cost;
            this.arr = arr;
        }
        
        @Override
        public int compareTo(Pair p) {
            return Integer.compare(cost, p.cost);
        }
    }
}