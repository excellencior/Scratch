mem = {}

def countConstruct(target, words):
    if target in mem:
        return mem[target]
    if target == '':
        return 1
    
    total_count = 0
    for word in words:
        if target.startswith(word):
            total_count += countConstruct(target[len(word):], words)
            
    mem[target] = total_count
    return total_count


print(countConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])) # 1
print(countConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])) # 0
print(countConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])) # 4
print(countConstruct("eeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeee", "eeeee", "eeeeee"])) # 0
print(countConstruct("purple", ["purp", "p", "ur", "le", "purpl"])) # 2