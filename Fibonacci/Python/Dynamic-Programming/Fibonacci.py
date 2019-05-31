# Fibonacci series using dynamic programming

# Calculate Fibonacci for n
def fibonacci(n):
    fib = [0,1] # n=0 : 0 | n=1 : 1
    for i in range(2,n+1):
        fib.append(fib[i-2] + fib[i-1])
    return fib[n]

value = int(input("Enter value:\n"))
result = fibonacci(value)
print("Fibonacci for {0} is {1}".format(value, result))