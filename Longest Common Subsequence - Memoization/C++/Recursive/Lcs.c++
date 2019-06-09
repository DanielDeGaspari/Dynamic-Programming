#include <iostream>
#include <string>
using namespace std;

/**
 * Recursive implementation of LCS problem
 */

string lcs(string s1, string s2, string result) {
    //base case: s1 || s2 = empty;
    if (s1.length() == 0 || s2.length() == 0) {
        return result; //Length == 0
    }
    //recursive case 1: s1[0] == s2[0]
    if (s1.substr(0,1).compare(s2.substr(0,1)) == 0) {
        return lcs(s1.substr(1), s2.substr(1), result.append(s1.substr(0,1)));
    }
    //calculate lcs for s1[1..s1.length()] and s2
    string sx = lcs(s1.substr(1), s2, result);
    //calculate lcs for s1 and s2[1..s2.length()]
    string dx = lcs(s1, s2.substr(1), result);
    return sx.length() >= dx.length() ? sx : dx;
}

int main() {
    string s1;
    string s2;
    cout << "Insert first word:"<<endl;
    cin >> s1;
    cout << "Insert second word:"<<endl;
    cin >> s2;
    string result = lcs(s1,s2, "");
    cout << "Longest common subsequence for" << endl << s1 << endl << s2 << endl;
    cout << "is: " << result << " and has length: " << result.length() << endl;
    return 0;
}