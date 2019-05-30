#include <iostream>
#include <string>
using namespace std;

/**
 * Recursive implementation of LCS problem
 */

 int max(int a, int b) {
     return a>b ? a : b;
 }

 int lcs(string s1, string s2) {
    //base case: s1 || s2 = empty;
    if (s1.length() == 0 || s2.length() == 0) {
        return 0;
    }
    //recursive case 1: s1[0] == s2[0]
    if (s1.substr(0,1).compare(s2.substr(0,1)) == 0) {
        return 1 + lcs(s1.substr(1,s1.length()-1), s2.substr(1,s2.length()-1));
    }
    //recursive case 2: s1[0] != s2[0]
    return max(lcs(s1.substr(1,s1.length()-1) , s2), lcs(s1, s2.substr(1,s2.length()-1)));
 }

int main() {
    string s1;
    string s2;
    cout << "Insert first word:"<<endl;
    cin >> s1;
    cout << "Insert second word:"<<endl;
    cin >> s2;
    cout << "Longest common subsequence for" << endl << s1 << endl << s2 << endl << "has length: " << lcs(s1,s2) << endl;
    return 0;
}