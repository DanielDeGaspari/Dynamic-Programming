# Longest Increasing Subsequence (LIS) problem using recursion

# calculate max(a,b)
def max(a,b):
    if a >= b:
        return a
    return b

def localLis(array, dim, i, currentMax):
    # base case
    if i == dim:
        return 0
    # recursive case 1: array[i] >= currentMax
    if array[i] >= currentMax:
        return 1 + localLis(array, dim, i+1, array[i])
    # recursive case 2: array[i] < max : ignore current value
    return localLis(array, dim, i+1, currentMax)

# Calculate LIS
def lis(array, dim, i, maximum):
    # base case
    if i >= dim-1:
        return maximum
    # recursive case
    return max(localLis(array, dim, i, maximum), lis(array, dim, i+1, maximum))

value = raw_input("Enter value:\n")
array = [int(x) for x in value.split(" ")]
result = lis(array, len(array), 0, 1)
print("Longest Increasing Subsequence (LIS) for {0} has length: {1}".format(value, result))