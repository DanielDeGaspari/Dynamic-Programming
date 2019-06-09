import java.util.Scanner;

/**
 * Recursive implementation of LCS problem
 */
public class Lcs{

    private static String lcs(String s1, String s2) {
        //Base case:
        if (s1.isEmpty() || s2.isEmpty()) {
            return "";
        }
        //Recursive case 1: s1[0] == s2[0]
        if (s1.substring(0,1).equals(s2.substring(0,1))){
            return s1.substring(0,1) + lcs(s1.substring(1),s2.substring(1));
        }
        //Recursive case 2: s1[0] != s2[0]
        String sx = lcs(s1, s2.substring(1));
        String dx = lcs(s1.substring(1), s2);
        return sx.length() >= dx.length() ? sx : dx;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insert first word:");
        String s1 = scanner.next();
        System.out.println("Insert second word:");
        String s2 = scanner.next();
        scanner.close();
        //Calculate result
        String result = lcs(s1,s2);
        String output = String.format("Long common subsequence for \n %s \n %s \nis: %s and has length: %s", s1, s2, result, result.length());
        System.out.println(output);
    }
}