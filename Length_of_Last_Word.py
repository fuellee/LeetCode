class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        words = s.split()
        if words == []:
            return 0
        else:
            return len(words[-1])
