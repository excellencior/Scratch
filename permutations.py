def permute(nums):
    if len(nums) == 0:
        return [[]]
    
    perms = []
    for i in range(len(nums)):
        # Take permute except a number selected
        res = permute(nums[:i] + nums[i+1:])
        for p in res:
            perms.append(p + [nums[i]])
    
    return perms

print(permute([1, 2, 3]))