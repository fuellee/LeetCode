n2str = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"];

import itertools
def letterCombinations(digits):
        digits = [ord(c)-ord('0') for c in digits]
        strs = [n2str[n] for n in digits]
        return [''.join(loc) for loc in itertools.product(*strs)]

print letterCombinations("23")
