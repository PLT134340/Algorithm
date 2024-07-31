import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int lv = scanner.nextInt();
        String judgement = scanner.next();
        
        if (judgement.equals("miss"))
            System.out.println(0);
        else if (judgement.equals("bad"))
            System.out.println(200 * lv);
        else if (judgement.equals("cool"))
            System.out.println(400 * lv);
        else if (judgement.equals("great"))
            System.out.println(600 * lv);
        else
            System.out.println(1000 * lv);
    }   
}