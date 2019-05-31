#include <iostream>
using namespace std;

/** Fibonacci series using recursion **/

//n=0: 0
//n=1: 1
int fibonacci(int n) {
    //base case
    if (n < 2) {
        return n;
    }

    //recursive case
    return fibonacci(n-2) + fibonacci(n-1);
}

int main() {
    int n;
    cout << "Enter value:"<<endl;
    cin >> n;
    cout << "Fibonacci for " << n << " : " << fibonacci(n) << endl;
    return 0;
}