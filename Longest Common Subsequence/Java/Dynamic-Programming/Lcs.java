import java.util.Objects;
import java.util.Scanner;

/**
 * Dynamic programming implementation of Longest Common Subsequence problem
 */
public class Lcs {

    private static int lcs(String s1, String s2) {
        Integer[][] lcs = new Integer[s1.length()+1][s2.length()+1];
        
        for (int i=0; i<=s1.length(); i++) {
            for (int j=0; j<=s2.length(); j++) {
                if (i==0 || j==0) {
                    lcs[i][j] = 0;
                } else {
                    if (Objects.equals(s1.subSequence(i-1, i), s2.subSequence(j-1, j))) {
                        lcs[i][j] = 1 + lcs[i-1][j-1];
                    } else {
                        lcs[i][j] = Integer.max(lcs[i][j-1], lcs[i-1][j]);
                    }
                }
            }
        }
        return lcs[s1.length()][s2.length()];
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