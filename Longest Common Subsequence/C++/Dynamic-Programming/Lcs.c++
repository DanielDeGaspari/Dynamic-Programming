#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) {
    return a>b ? a : b;
}

int lcs(string s1, string s2) {

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
    
    return lcs[s1.length()][s2.length()];
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
