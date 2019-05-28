import java.util.Scanner;

/**
 * Fibonacci series using dynamic programming
 */
public class Fibonacci {

    private static int fibonacci(int n) {

        //Store Fibonacci numbers in an array
        int[] fib = new int[n + 2];
        fib[0] = 0; //n=0 : 0;
        fib[1] = 1; //n=1 : 1;

        for (int i = 2; i <= n; i++) {
            // Store the result of sum of previous 2 numbers
            fib[i] = fib[i - 2] + fib[i - 1];
        }
        
        return fib[n];
    }

    public static void main(String args[]) {
        System.out.println("Insert value:");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        //Calculate result
        String result = String.format("Fibonacci for %s : %s", n, fibonacci(n));
        System.out.println(result);
    }

}



