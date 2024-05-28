import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int s = Integer.parseInt(line[1]);
        
        line = br.readLine().split(" ");
        int[] score = new int[n];
        
        for (int i = 0; i < n; i++)
            score[i] = Integer.parseInt(line[i]);
        
        int leftIdx = s - 2;
        int rightIdx = s;
        long mid = score[s - 1];
        long leftSum = 0;
        long rightSum = 0;
        long leftSumMax = 0;
        long rightSumMax = 0;
        boolean isChanged = true;
        
        while (isChanged) {
            isChanged = false;
            while (leftIdx >= 0 && mid + rightSumMax + leftSum + score[leftIdx] >= 0) {
                leftSum += score[leftIdx--];
                isChanged = true;
                if (leftSumMax < leftSum)
                    leftSumMax = leftSum;
            }
            while (rightIdx < n && mid + leftSumMax + rightSum + score[rightIdx] >= 0) {
                rightSum += score[rightIdx++];
                isChanged = true;
                if (rightSumMax < rightSum)
                    rightSumMax = rightSum;
            }
        }
        
        // System.out.println(mid);
        // System.out.println(leftSumMax);
        // System.out.println(rightSumMax);
        
        System.out.println(mid + leftSumMax + rightSumMax);
    }   
}