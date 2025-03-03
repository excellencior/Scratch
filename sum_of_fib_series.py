def fib(n):
    if n <= 1:
        return 1
    
    dp = [0, 1]
    ans = 1
    
    for i in range(2, n+1):
        dp.append(dp[i-1] + dp[i-2])
        ans += dp[i]
    
    print("Sum :", ans)

fib(5)

# Using a formula
# Sum of the n numbers in the fibonacci series = f(n+2) - 1

def fib(n, memo={}):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    
    if n in memo:
        return memo[n]
    
    memo[n] = fib(n-1) + fib(n-2)
    return memo[n]

def sum_fib(n):
    return fib(n+2) - 1

print("Sum :", sum_fib(5))