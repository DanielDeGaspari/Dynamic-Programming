#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**
 * Recursive implementation of Longest Increasing Subsequence (LIS) 
 * problem using recursion
 */

/**
 * Calculate max(a,b)
 */
int max(int a, int b) {
    return a>b ? a : b;
}

int localLis(int* array, int dim, int i, int currentMax) {
    // base case: i == dim
    if (i == dim) {
        return 0;
    }
    // recursive case 1: array[i] >= currentMax
    if (array[i] >= currentMax) {
        return 1 + localLis(array, dim, i+1, array[i]);
    }
    // recursive case 2: array[i] < currentMax
    return localLis(array, dim, i+1, currentMax);
}

/**
 * Calculate LIS
 */
int lis(int* array, int dim, int i, int maximum) {
    // base case: i >= dim-1
    if (i >= dim-1) {
        return maximum;
    }
    // recursive case:
    int includeCurrent = localLis(array, dim, i, array[i]);
    int excludeCurrent = lis(array, dim, i+1, maximum);
    return max(includeCurrent, excludeCurrent);
}

int main() {
    // Read value
    string input;
    cout << "Enter value:" << endl;
    getline(cin, input);

    // Convert string to int array
    int array[input.length()];
    istringstream ss(input);
    string current;
    int dim = 0;
    while(getline(ss, current, ' ')) {
        istringstream iss(current);
        iss >> array[dim];
        dim++;
    }

    int result = lis(array, dim, 0, 1);
    cout << "Longest Increasing Subsequence (LIS) for: " << input << " has length: " << result << endl;
}