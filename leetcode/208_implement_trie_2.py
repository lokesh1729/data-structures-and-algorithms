class Node:
    def __init__(self, char):
        self.char = char
        self.children = [None for _ in range(26)]
        self.is_word = False
 
 
class Trie:
 
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node('X')
 
    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if not word:
            return
        curr_root = self.root
        for char in word:
            pos = ord(char) % 26
            curr_node = curr_root.children[pos]
            if curr_node is not None:
                curr_root = curr_node
            else:
                new_node = Node(char)
                curr_root.children[pos] = new_node
                curr_root = new_node
        curr_root.is_word = True
 
    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        curr_root = self.root
        for char in word:
            pos = ord(char) % 26
            if curr_root.children[pos] is None:
                return False
            curr_root = curr_root.children[pos]
        return curr_root.is_word
 
    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        curr_root = self.root
        for char in prefix:
            pos = ord(char) % 26
            if curr_root.children[pos] is None:
                return False
            curr_root = curr_root.children[pos]
        return True
