class Main {
    public static void main(String[] args) {
        boolean[] isNotGenerator = new boolean[10001];
        for (int i = 1; i <= 10000; i++) {
            int sum = i;
            int tmp = i;
            while (tmp > 0) {
                sum += tmp % 10;
                tmp /= 10;
            }
            
            if (sum <= 10000)
                isNotGenerator[sum] = true;
        }
        
        for (int i = 1; i <= 10000; i++)
            if (!isNotGenerator[i])
                System.out.println(i);
    }
}