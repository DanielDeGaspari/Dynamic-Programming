# Fibonacci series using recursion

# n=0 : 0
# n=1 : 1
# Calculate Fibonacci for n
def fibonacci(n):
    # base case
    if n < 2:
        return n
    # recursive case
    return fibonacci(n-1) + fibonacci(n-2)

value = int(input("Enter value:\n"))
result = fibonacci(value)
print("Fibonacci for {0} is {1}".format(value, result))