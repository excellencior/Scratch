def combinate(nums, r):
    res = []

    def solve(start, comb):
        if len(comb) == r:
            res.append(comb[:])
            return
        
        for i in range(start, len(nums)):
            comb.append(nums[i])
            solve(i+1, comb)
            comb.pop()
            
    solve(0, [])
    return res


print(combinate([1, 2, 3], 2))