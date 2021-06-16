class Trie:
    def __init__(self, char=None, pos=-1):
        self.char = char
        self.pos = pos
        self.palindromes = []
        self.children = {}


class Solution:
    
    def add(self, root: Trie, word: str, pos: int):
        for i in range(len(word) - 1, -1, -1):
            if word[i] not in root.children:
                root.children[word[i]] = Trie(word[i])
            if self.is_palindrome(word, 0, i):
                root.palindromes.append(pos)
            root = root.children[word[i]]
        root.pos = pos
        # if strings are of same length
        # example "abcd" & "dbca"
        root.palindromes.append(pos)
    
    def search(self, root, word, pos, result):
        for index, char in enumerate(word):
            if root == None:
                break
            # if there's a word ended at pos and
            # root.pos != pos to avoid duplicates
            # then check if the remaining string is
            # palindrome. for example, "abc", "cbafzf"
            # if length of current string is > comparing string
            if root.pos >= 0 and root.pos != pos and self.is_palindrome(word, index, len(word)-1):
                result.append([pos, root.pos])
            root = root.children.get(char)
        # if the length of current string is < comparing string
        # example "fzfabc" "cba"
        if root != None and root.palindromes:
            for idx in root.palindromes:
                if idx != pos:
                    result.append([pos,idx])

    def is_palindrome(self, word, start, end):
        while start < end:
            if word[end] != word[start]:
                return False
            end -= 1
            start += 1
        return True

    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        root = Trie()
        result = []
        for pos, word in enumerate(words):
            self.add(root, word, pos)
        for pos, word in enumerate(words):
            self.search(root, word, pos, result)
        return result

