import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        Pair[] a = new Pair[n];
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            a[i] = new Pair(val, i);
        }
        
        int m = scanner.nextInt();
        Pair[] b = new Pair[m];
        for (int i = 0; i < m; i++) {
            int val = scanner.nextInt();
            b[i] = new Pair(val, i);
        }
        
        Arrays.sort(a, Collections.reverseOrder());
        Arrays.sort(b, Collections.reverseOrder());
        
        int i = 0;
        int j = 0;
        int iIdx = 0;
        int jIdx = 0;
        ArrayList<Integer> arrayList = new ArrayList<>();
        
        while (i < n && j < m)
            if (a[i].val > b[j].val)
                i++;
            else if (a[i].val < b[j].val)
                j++;
            else {
                if (arrayList.isEmpty() || a[i].idx > iIdx && b[j].idx > jIdx) {
                    arrayList.add(a[i].val);
                    iIdx = a[i].idx;
                    jIdx = b[j].idx;
                    i++;
                    j++;
                } else if (a[i].idx > iIdx)
                    j++;
                else if (b[j].idx > jIdx)
                    i++;
                else {
                    i++;
                    j++;
                }
            }
        
        System.out.println(arrayList.size());
        for (int val : arrayList)
                System.out.print(val + " ");
    }
    
    static class Pair implements Comparable<Pair> {
        public int val;
        public int idx;
        
        public Pair(int val, int idx) {
            this.val = val;
            this.idx = idx;
        }
        
        @Override
        public int compareTo(Pair p) {
            if (val == p.val) {
                if (idx == p.idx)
                    return 0;
                else if (idx < p.idx)
                    return 1;
                else
                    return -1;
            } else if (val < p.val)
                return -1;
            else
                return 1;
        }
    }
}