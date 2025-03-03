def isValid(number):
    if len(number) == 10:
        return number.isnumeric()
    else:
        nums = number.split('-')
        if len(nums) != 3 or len(nums[0])!=3 or len(nums[1])!=3 or len(nums[2])!=4:
            return False
        return nums[0].isnumeric() and nums[1].isnumeric() and nums[2].isnumeric()

def check(numbers):
    for number in numbers:
        if isValid(number):
            print("Valid")
        else:
            print("Invalid")
        


numbers = [
    "123-456-7890",  # Valid (xxx-xxx-xxxx)
    "1234567890",     # Valid (xxxxxxxxxx)
    "123-456-789",    # Invalid (incorrect length)
    "1234-567-890",   # Invalid (incorrect format)
    "123-45X-7890",   # Invalid (contains non-numeric character)
    "12-345-67890",   # Invalid (incorrect format)
    "987-654-3210",   # Valid (xxx-xxx-xxxx)
    "9876543210",     # Valid (xxxxxxxxxx)
    "123-4567890",    # Invalid (missing part of the format)
    "123-456-78900",  # Invalid (incorrect length)
    "987-654-321X",   # Invalid (contains non-numeric character)
    "123456789X",     # Invalid (contains non-numeric character)
    "123-123-1234",   # Valid (xxx-xxx-xxxx)
    "9999999999",     # Valid (xxxxxxxxxx)
]

check(numbers)