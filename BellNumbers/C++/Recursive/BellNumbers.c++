#include <iostream>
using namespace std;

/**
 * Bell numbers using recursion
 */

//Calculate factorial for num
int factorial(int num) {
    //base case
    if (num == 0) {
        return 1;
    }
    return num * factorial(num-1);
}

//Calculate combination: nCi
int combine(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n-k));
}

//Calculate Bell number for n
int bellNumbers(int n, int k, int sum) {
     //base case 1
     if (n == 0) {
         return 1; //B(0) = 1
     }
     //base case 2
     if (k == n) {
         return 0;
     }
     //recursive case
     sum += bellNumbers(n,k+1,sum);
     sum += combine(n-1,k) * bellNumbers(k,0,0);
     return sum;
 }

 int main() {
    int n;
    cout << "Insert value:"<<endl;
    cin >> n;
    cout << "Bell numbers for " << n << " : " << bellNumbers(n, 0, 0) << endl;
    return 0;
 }