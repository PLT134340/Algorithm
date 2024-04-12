import java.util.*;

class Solution {
    public String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        
        Pair[] pairs = { new Pair(3, 1), 
                new Pair(0, 0), new Pair(0, 1), new Pair(0, 2),
                new Pair(1, 0), new Pair(1, 1), new Pair(1, 2),
                new Pair(2, 0), new Pair(2, 1), new Pair(2, 2) };
        
        Pair left = new Pair(3, 0);
        Pair right = new Pair(3, 2);
        
        for (int i = 0; i < numbers.length; i++)
            if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
                sb.append("L");
                left = pairs[numbers[i]];
            } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
                sb.append("R");
                right = pairs[numbers[i]];
            } else {
                int lengthFromLeft = Math.abs(left.getRow() - pairs[numbers[i]].getRow()) 
                    + Math.abs(left.getCol() - pairs[numbers[i]].getCol());
                int lengthFromRight = Math.abs(right.getRow() - pairs[numbers[i]].getRow()) 
                    + Math.abs(right.getCol() - pairs[numbers[i]].getCol());
                
                if (lengthFromLeft < lengthFromRight) {
                    sb.append("L");
                    left = pairs[numbers[i]];
                } else if (lengthFromLeft > lengthFromRight) {
                    sb.append("R");
                    right = pairs[numbers[i]];
                } else if (hand.equals("left")) {
                    sb.append("L");
                    left = pairs[numbers[i]];
                } else {
                    sb.append("R");
                    right = pairs[numbers[i]];
                }
            }
        
        return sb.toString();
    }
}

class Pair {
    private int row;
    private int col;
    
    public Pair(int row, int col) {
        this.row = row;
        this.col = col;
    }
    
    int getRow() {
        return row;
    }
    
    int getCol() {
        return col;
    }
};