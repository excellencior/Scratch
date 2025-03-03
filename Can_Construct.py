mem = {}

def canConstruct(target, wordBank):
    if target in mem:
        return mem[target]
    
    if target == '':
        return True
    
    for word in wordBank:
        if target.startswith(word):
            if canConstruct(target[len(word):], wordBank):
                mem[target] = True
                return True
    mem[target] = False
    return False

print(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])) # True
print(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])) # False
print(canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])) # True
print(canConstruct("eeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeee", "eeeee", "eeeeee"])) # False