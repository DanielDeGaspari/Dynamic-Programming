# Fibonacci

## Short description:

The Fibonacci numbers are defined as following:

fib(n) = n -&gt; for n &lt;= 1

fib(n) = fib(n-1) + fib(n-2) -&gt; for n &gt; 1

Example: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, etc

## Recursive Approach

Solution using recursion:

Time Complexity: T(n) = T(n-1) + T(n-2) + 1 = 2<sup>n</sup> = O(2<sup>n</sup>)

Space Complexity: O(1)

## Dynamic Approach

Solution using dynamic programming:

Time Complexity: O(n)

Space Complexity: O(n)
