import java.util.Scanner;

public class BellNumbers {

    //Calculate factorial for num
    private static int factorial(int num) {
        //base case:
        if (num <=1) {
            return 1;
        }
        return num * factorial(num-1);
    }

    //Calculate combination nCk
    private static int combine(int n, int k) {
        return factorial(n) / (factorial(k) * factorial(n-k));
    }

    //Calculate Bell Number for n
    private static int bellNumbers(int n) {
        //Store Combination calculated
        int[][] bellMatrix = new int[100][100];

        bellMatrix[0][0] = 1; //B(0) = 1;

        //bellMatrix[0..i-1][] contains bellNumber as the rightmost value;
        for (int i=1; i<=n; i++) {
            bellMatrix[i][0] = bellMatrix[i-1][i-1]; //rightmost value = previous Bell number
            for (int j=1; j<=i; j++) {
                bellMatrix[i][j] = bellMatrix[i-1][j-1] + bellMatrix[i][j-1];
            }
        }
        return bellMatrix[n][0];
    }

    public static void main(String args[]) {
        System.out.println("Insert value:");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        //Calculate result
        String result = String.format("Bell number for %s : %s", n, bellNumbers(n));
        System.out.println(result);
    }
}