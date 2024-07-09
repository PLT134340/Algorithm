import java.util.*;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        BigInteger n = scanner.nextBigInteger();
        BigInteger m = scanner.nextBigInteger();
        
        System.out.println(n.divide(m));
        System.out.println(n.remainder(m));
    }   
}