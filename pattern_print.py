def pattern(n):
    if n < 0:
        print(n)
        return
    
    print(n)
    
    pattern(n - 5)
    
    print(n)
    
pattern(7)