# Generate all possible non-empty subsets

def generate(nums):
    res = []
    def subsets(idx, curr):
        if curr:
            res.append(curr[:])
        
        for i in range(idx, len(nums)):
            curr.append(nums[i])
            subsets(i+1, curr)
            curr.pop()
            
    subsets(0, [])
    return res

print(generate([1, 2, 3]))