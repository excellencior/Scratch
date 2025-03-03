def subtract_strings(num1: str, num2: str) -> str:
    """
    Subtract two large numbers represented as strings (num1 - num2).
    Assumes num1 is greater than or equal to num2.
    """
    num1, num2 = num1[::-1], num2[::-1]
    res = []
    borrow = 0
    for i in range(len(num1)):
        n1 = int(num1[i])
        n2 = int(num2[i]) if i < len(num2) else 0
        
        diff = n1 - n2 - borrow
        if diff < 0:
            diff += 10
            borrow = 1
        else:
            borrow = 0
        
        res.append(str(diff))
    
    while len(res) and res[-1]=='0':
        res.pop()
        
    return ''.join(res[::-1])

def run_test_cases():
    test_cases = [
        ("12345678901234567890", "12345678901234567889"),  # 1
        ("98765432198765432100", "123456789123456789"),    # 98641975409641975311
        ("1000", "999"),                                   # 1
        ("5000000000", "123456789"),                       # 4876543211
        ("1234", "1233"),                                  # 1
    ]

    for num1, num2 in test_cases:
        print(f"{num1} - {num2} = {subtract_strings(num1, num2)}")


run_test_cases()