#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) {
    return a>b ? a : b;
}

string lcs(string s1, string s2) {
    int lcs[s1.length()+1][s2.length()+1];

    for (int i=0; i<=s1.length(); i++) {
        for (int j=0; j<=s2.length(); j++) {
            if (i==0 || j==0) {
                lcs[i][j] = 0;
            } else {
                if (s1.substr(i-1,1).compare(s2.substr(j-1,1)) == 0) {
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                } else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
    }

    //find LCS string
    int i = s1.length();
    int j = s2.length();
    int index = lcs[i][j];
    char result[index+1];
    result[index] = '\0'; // Set the terminating character 
    while (i>0 && j>0) {
        if (s1.substr(i-1,1).compare(s2.substr(j-1,1)) == 0) { //is a match
            result[index-1] = s1[i-1];
            i--;
            j--;
            index--;
        } else {
            if (lcs[i-1][j] > lcs[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    
    return std::string(result);
}

int main() {
    string s1;
    string s2;
    cout << "Insert first word:"<<endl;
    cin >> s1;
    cout << "Insert second word:"<<endl;
    cin >> s2;
    string result = lcs(s1,s2);
    cout << "Longest common subsequence for" << endl << s1 << endl << s2 << endl;
    cout << "is: " << result << " and has length: " << result.length() << endl;
    return 0;
}
