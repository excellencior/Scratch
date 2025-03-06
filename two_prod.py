def two_prod(nums, target):
    if len(nums) < 2:
        raise ValueError("At least two numbers are required.")
    
    nums.sort()  # Sorting for two-pointer method
    n = len(nums)
    i, j = 0, n - 1
    x, y = nums[i], nums[j]

    min_dist = abs(x*y - target)

    while i < j:
        product = nums[i] * nums[j]
        current_dist = abs(product - target)

        if current_dist < min_dist:
            min_dist = current_dist
            x, y = nums[i], nums[j]

        # Move pointers based on the product
        if product < target:
            i += 1
        else:
            j -= 1

    return [x, y]


# Test cases
test_cases = [
    # Basic case with clear closest product
    ([2, 6, 7], 30),  # Expected: [6, 5] or [5, 6], product closest to 30
    
    # Case with multiple possible pairs
    ([1, 3, 4, 6, 7], 10),  # Expected: [3, 3] or some pair with product close to 10
    
    # Case with negative numbers
    ([-1, -2, 3, 4, 5], 10),  # Expected: [-2, -5] or pair closest to 10
    
    # Case with all positive numbers
    ([1, 2, 3, 4, 5], 12),  # Expected: [3, 4] with product 12
    
    # Case with duplicates
    ([2, 2, 2, 2, 2], 4),  # Expected: [2, 2]
    
    # Case with very different numbers
    ([100, 1, 50, 3, 200], 1000),  # Expected: [100, 10] or closest pair
    
    # Case with zero included
    ([0, 1, 2, 3, 4], 6),  # Expected: [2, 3]
    
    # Case with very small numbers
    ([0.1, 0.2, 0.3, 0.4, 0.5], 0.2),  # Expected: [0.1, 0.2] or closest pair
    
    # Case with empty list (edge case, would raise an error)
    ([], 10),  # Expected: ValueError or appropriate error handling
]

# Function to print test cases
def print_test_cases():
    for nums, target in test_cases:
        print(f"Numbers: {nums}, Target: {target}")
        # Uncomment and implement actual testing once two_prod is complete
        try:
            result = two_prod(nums, target)
            print(f"Result: {result}")
        except Exception as e:
            print(f"Error: {e}")
        print("-" * 30)

# Call to print test cases
print_test_cases()