class Trie:
    def __init__(self, val, is_word_end, original_index):
        self.char = val
        self.is_word_end = is_word_end
        self.original_index = original_index
        self.children = {}


def print_trie(root, curr_str):
    if root.is_word_end:
        print(curr_str)
        return
    
    for char, node in root.children.items():
        print_trie(node, curr_str + char)
    


def prefix_search(words, search):
    if search is None:
        return []
    root = Trie("X", False, -1)
    for idx, word in enumerate(map(lambda i: i.lower(), filter(lambda i: i is not None, words))):
        for split_word in word.split():
            curr_root = root
            for each_char in split_word:
                if curr_root.children.get(each_char) is not None:
                    curr_root = root.children[each_char]
                else:
                    new_node = Trie(each_char, False, idx)
                    curr_root.children[each_char] = new_node
                    curr_root = new_node
            curr_root.is_word_end = True
    # print_trie(root, "")
    new_root = root
    indexes = set()
    for each_char in search.lower():
        if new_root.children.get(each_char) is None:
            return []
        new_root = new_root.children[each_char]
    queue = []
    queue.append(new_root)
    while queue:
        curr_node = queue.pop(0)
        indexes.add(curr_node.original_index)
        for each_node in curr_node.children.values():
            queue.append(each_node)
    
    result = []
    for idx in indexes:
        result.append(words[idx])
    return result
    

if __name__ == "__main__":
    print(prefix_search(["Flipkart", "HDFC Bank", "Grofers", "Facebook"], "fac"))
    print(prefix_search(["Flipkart", "HDFC Bank", "Grofers", "Facebook"], "ban"))
    print(prefix_search(["Flipkart", "HDFC Bank", "Grofers", "Facebook"], "fli"))
    print(prefix_search(["Flipkart", "HDFC Bank", "Grofers", "Facebook"], "f"))
    print(prefix_search([None], None))
    print(prefix_search([None], "abc"))

# 
# Your previous Java content is preserved below:
# 
# /*
#  * Click `Run` to execute the snippet below!
#  */
# 
# import java.io.*;
# import java.util.*;
# 
# /*
#  
#  Build a prefix based seerch for a mobile phone app's.
#  
#  For eg:- 
#  App Name
#  
#  FlipKart
#  HDFC Bank
#  Grofers
#  Facebook
#  
#  Test Case:-
#  Prefix -> f
#  
#  Exp O/P -> FlipKart, Facebook
#  
#  Prefix -> ban
#  
#  Exp O/P -> HDFC Bank
#                  ban
#                  
#                  O(n*n*k) => O(n^2 * k)
#  
#  h b f
#  d a l
#  f n i
#  c k p
#  
#  O(n + n*k) => O(n*k)
# x
#
#  
# 
#  */
# 
# class Solution {
#   public static void main(String[] args) {
#     ArrayList<String> strings = new ArrayList<String>();
#     strings.add("Hello, World!");
#     strings.add("Welcome to CoderPad.");
#     strings.add("This pad is running Java " + Runtime.version().feature());
# 
#     for (String string : strings) {
#       System.out.println(string);
#     }
#   }
# }
# 

