#include <iostream>
using namespace std;

//Calculate Bell Number for n
int bellNumbers(int n) {
    //Store previous Bell Numbers
    int bellMatrix[100][100];
    bellMatrix[0][0] = 1; //B(0) = 1;

    //bellMatrix[0..i-1][] contains bellNumber as the rightmost value;
    for (int i=1; i<=n; i++) {
        bellMatrix[i][0] = bellMatrix[i-1][i-1]; //rightmost value = previous Bell number
        for (int j=1; j<=i; j++) {
            bellMatrix[i][j] = bellMatrix[i][j-1] + bellMatrix[i-1][j-1];
        }
    }
    return bellMatrix[n][0];
}

int main() {
    int n;
    cout << "Insert value:"<<endl;
    cin >> n;
    cout << "Bell numbers for " << n << " : " << bellNumbers(n) << endl;
    return 0;
}