import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int x = scanner.nextInt();
        String str = scanner.next();

        int man = 0;
        int woman = 0;
        int waiting = -1;

        for (int i = 0; i < str.length(); i++) {
            int abs = Math.abs(man - woman);
            if (waiting != -1) {
                if (abs == x && str.charAt(waiting) == str.charAt(i))
                    break;

                man++;
                woman++;
                waiting = -1;
            } else if (abs == x && (man > woman && str.charAt(i) == 'M' || man < woman && str.charAt(i) == 'W'))
                waiting = i;
            else if (str.charAt(i) == 'M')
                man++;
            else
                woman++;
        }

        System.out.println(man + woman);
    }
}