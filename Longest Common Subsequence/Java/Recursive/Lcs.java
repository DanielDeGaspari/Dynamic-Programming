import java.util.Scanner;

/**
 * Recursive implementation of LCS problem
 */
public class Lcs {

    //calculate local LCS
    private static int lcs(String s1, String s2) {
        //base case: s1 || s2 = empty;
        if (s1.isEmpty() || s2.isEmpty()) {
            return 0;
        }
        //recursive case 1: s1[0] != s2[0]
        if (!s1.substring(0,1).equals(s2.substring(0,1))) {
            return Integer.max(lcs(s1.substring(1), s2), lcs(s1, s2.substring(1)));
        }
        //recursive case 2: s1[0] == s2[0]
        return 1 + lcs(s1.substring(1), s2.substring(1));
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insert first word:");
        String s1 = scanner.next();
        System.out.println("Insert second word:");
        String s2 = scanner.next();
        scanner.close();
        //Calculate result
        String result = String.format("Long common subsequence for \n %s \n %s \nhas length: %s", s1, s2, lcs(s1,s2));
        System.out.println(result);
    }
}