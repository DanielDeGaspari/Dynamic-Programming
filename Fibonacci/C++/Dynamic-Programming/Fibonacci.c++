#include <iostream>
using namespace std;

/**
 * Fibonacci series using dynamic programming
 */
int fibonacci(int n) {

    //Store Fibonacci numbers in an array
    int fib [n+2];
    fib[0] = 0; //n=0 : 0;
    fib[1] = 1; //n=1 : 1;

    for (int i=2; i<=n; i++) {
        fib[i] = fib[i-2]+fib[i-1];
    }

    return fib[n];
}

int main() {
    int n;
    cout << "Insert value:"<<endl;
    cin >> n;
    cout << "Fibonacci for " << n << " : " << fibonacci(n) << endl;
    return 0;
}