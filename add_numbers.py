def add(num1: str, num2: str):
    n1, n2 = len(num1), len(num2)
    
    i, carry = 1, 0
    res = []
    while i <= n1 and i <= n2:
        sum = int(num1[n1-i]) + int(num2[n2-i]) + carry
        i += 1
        carry = sum // 10
        res = [str(sum % 10)] + res
    
    while i < n1:
        res = [num1[i]] + res
        i += 1
    while i < n2:
        res = [num2[i]] + res
        i += 1
    
    return res

print(add(['1', '2', '3'], ['2', '8', '5'])) # ['4', '0', '8']
print(add(['1', '2', '3'], ['4', '5', '6'])) # ['5', '7', '9']