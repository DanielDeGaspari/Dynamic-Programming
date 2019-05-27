import java.util.Scanner;

/**
 * Fibonacci series using recursion
 */
public class Fibonacci {

    //n=0: 0
    //n=1: 1
    static int fibonacci(int n) {
        //base case
        if (n < 2) {
            return n;
        }
        //recursive case
        return fibonacci(n - 2) + fibonacci(n - 1);
    }

    public static void main(String args[]) {
        System.out.println("Insert value:");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        //Calculate result
        String result = String.format("Fibonacci for %s : %s", n, fibonacci(n));
        System.out.println(result);
    }

}



