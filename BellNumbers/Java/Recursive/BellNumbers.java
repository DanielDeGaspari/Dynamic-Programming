import java.util.Scanner;

/**
 * Bell numbers using recursion
 */
public class BellNumbers {

    //calculate factorial for num
    private static int factorial(int num) {
        //base case
        if (num <= 1) {
            return 1;
        }
        //recursive case
        return num * factorial(num-1);
    }

    //Calculate combination: nCi
    private static int combine(int n, int k) {
        return factorial(n) / (factorial(k) * (factorial(n-k)));
    }

    //Calculate bellNumber for n
    private static int bellNumbers(int n, int k, int sum) {
        //base case 1
        if (n==0) {
            return 1;
        }
        //base case 2
        if (k==n) {
            return 0;
        }
        //recursive case
        sum += bellNumbers(n, k+1, sum);
        sum += combine(n-1, k) * bellNumbers(k, 0, 0);
        return sum;
    }

    public static void main(String args[]) {
        System.out.println("Insert value:");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        //Calculate result
        String result = String.format("Bell number for %s : %s", n, bellNumbers(n, 0, 0));
        System.out.println(result);
    }
}