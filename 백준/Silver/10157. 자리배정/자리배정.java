
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int c = scanner.nextInt();
        int r = scanner.nextInt();
        int k = scanner.nextInt();
        
        if (k > r * c) {
            System.out.println(0);
            return;
        }
        
        int lv = 0;
        int num = 0;
        int prevNum = 0;
        
        while (num < k) {
            prevNum = num;
            num += (r - 2 * lv) * 2 + (c - 2 * lv) * 2 - 4;
            lv++;
        }
        lv--;
        
        // System.out.println(String.format("lv=%d, num=%d, prevNum=%d", lv, num, prevNum));
        
        int leftDown = prevNum + 1;
        int leftUp = leftDown + (r - 2 * lv) - 1;
        int rightUp = leftUp + (c - 2 * lv) - 1;
        int rightDown = rightUp + (r - 2 * lv) - 1;
        
        // System.out.println(String.format("%d %d %d %d", leftDown, leftUp, rightUp, rightDown));
        
        if (k >= leftDown && k < leftUp)
            System.out.println((lv + 1) + " " + (lv + k - prevNum));
        else if (k >= leftUp && k < rightUp)
            System.out.println((lv + 1 + k - leftUp) + " " + (lv + (r - 2 * lv)));
        else if (k >= rightUp && k < rightDown)
            System.out.println((c - lv) + " " + (r - lv - (k - rightUp)));
        else
            System.out.println((lv + 1 + (num - k + 1)) + " " + (lv + 1));
    }
}