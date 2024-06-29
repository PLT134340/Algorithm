import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[] colors = new int[4];
        Pair[] numbers = new Pair[9];
        for (int i = 0; i < 9; i++)
            numbers[i] = new Pair(i + 1, 0);
        int maxNum = 0;
        
        for (int i = 0; i < 5; i++) {
            String color = scanner.next();
            int num = scanner.nextInt();
            
            if (color.equals("R"))
                colors[0]++;
            else if (color.equals("B"))
                colors[1]++;
            else if (color.equals("Y"))
                colors[2]++;
            else
                colors[3]++;
            
            numbers[num - 1].num++;
            
            if (maxNum < num)
                maxNum = num;
        }
        
        Integer[] colorsInteger = Arrays.stream(colors).boxed().toArray(Integer[]::new);
        Arrays.sort(colorsInteger, Collections.reverseOrder());
        Arrays.sort(numbers, Collections.reverseOrder());
        boolean isSerial = numbers[0].idx + 4 == numbers[4].idx && numbers[4].num == 1 ;
        
        // for (int i = 0; i < 9; i++)
        //     System.out.println(numbers[i].idx + ": " + numbers[i].num);
        
        int score;
        if (colorsInteger[0] == 5 && isSerial)
            score = maxNum + 900;
        else if (numbers[0].num == 4)
            score = numbers[0].idx + 800;
        else if (numbers[0].num == 3 && numbers[1].num == 2)
            score = numbers[0].idx * 10 + numbers[1].idx + 700;
        else if (colorsInteger[0] == 5)
            score = maxNum + 600;
        else if (isSerial)
            score = maxNum + 500;
        else if (numbers[0].num == 3)
            score = numbers[0].idx + 400;
        else if (numbers[0].num == 2 && numbers[1].num == 2)
            score = numbers[1].idx * 10 + numbers[0].idx + 300;
        else if (numbers[0].num == 2)
            score = numbers[0].idx + 200;
        else
            score = maxNum + 100;
        
        System.out.println(score);
    }

    static class Pair implements Comparable<Pair> {
        public int idx;
        public int num;

        public Pair(int idx, int num) {
            this.idx = idx;
            this.num = num;
        }

        @Override
        public int compareTo(Pair p) {
            if (num == p.num)
                if (idx < p.idx)
                    return 1;
                else if (idx == p.idx)
                    return 0;
                else
                    return -1;
            else if (num < p.num)
                return -1;
            else
                return 1;
        }
    }

}