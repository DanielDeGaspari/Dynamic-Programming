import java.util.Arrays;
import java.util.Scanner;
/**
 * Implementation of Longest Increasing Subsequence (LIS) 
 * problem using dynamic programming
 */

class Lis {

    private static int findMax(int[] lis) {
        return Arrays.stream(lis).max().getAsInt();
    }

    private static int lis(int[] array) {
        int[] lis = new int[array.length];
        // Lis for length = 1 is 1
        for (int i=0; i<array.length; i++) {
            lis[i] = 1;
        }
        // foreach dim, update lis
        for (int i=1; i<array.length; i++) {
            for (int j=0; j<i; j++) {
                if (array[i] > array[j] && lis[i] < lis[j] + 1) {
                    lis[i] = 1 + lis[j];
                }
            }
        }
        return findMax(lis);
    }

    static int[] parseIntArray(String s) {
        return Arrays.stream(s.split(" "))
            .mapToInt(Integer::parseInt)
            .toArray();
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insert number's sequence:");
        String input = scanner.nextLine();
        scanner.close();
        int[] array = parseIntArray(input);
        //Calculate result
        String result = String.format("Longest Increasing Subsequence (LIS) for %s has length: %s", input, lis(array));
        System.out.println(result);
    }
}