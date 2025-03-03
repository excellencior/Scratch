
def allConstruct(target, words):
    if target == '':
        return [[]]
    
    result = []
    for word in words:
        if target.startswith(word):
            suffixes = allConstruct(target[len(word):], words)
            suffixWays = [[word] + way for way in suffixes]
            result.extend(suffixWays)
    return result

print(allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd", "ef"])) # [['ab', 'cd', 'ef'], ['abc', 'def'], ['abcd', 'ef']]
print(allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])) # []
print(allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])) # [['enter', 'a', 'pot', 'ent', 'pot'], ['enter', 'a', 'pot', 'ent', 'p', 'ot'], ['enter', 'a', 'p', 'o', 'tent', 'pot'], ['enter', 'a', 'p', 'o', 'tent', 'p', 'ot']]
print(allConstruct("eeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeee", "eeeee", "eeeeee"])) # []
print(allConstruct("purple", ["purp", "p", "ur", "le", "purpl"])) # [['purp', 'le'], ['p', 'ur', 'p', 'le']]