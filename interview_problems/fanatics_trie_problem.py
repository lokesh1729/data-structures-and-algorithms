#  Input : contacts [] = {"anuj" , "amit", "amitabh" ,"mayank" }
#         Query String = "an"
#         {"anuj"}
#         
#         Trie
#         
#         a    m
#        / \
#       n   m
#      / \  / \ \ \
#     u   i i  e t s
#     /   / /
#    j    l t -> isWordEnd -> true
#           /
#           a
#           /
#           b
#           /
#           h -> isWordEnd -> true



import collections

class Trie:
    def __init__(self, character, is_word_end):
        self.character = character
        self.is_word_end = is_word_end
        self.children = [None for _ in range(26)]

        
def print_trie(root, res):
    if root is None:
        return
    if root is not None and root.is_word_end is True:
        print(res)
    for node in root.children:
        if node is not None:
            print_trie(node, res + node.character)


def main(contacts, query_string):
    result = []
    root = Trie('X', False)
    for contact in contacts:
        curr_node = root
        for each_char in contact:
            temp = curr_node.children[ord(each_char) - ord('a')]
            if curr_node.children[ord(each_char) - ord('a')] is not None:
                curr_node = temp
            else:
                new_node = Trie(each_char, False)
                curr_node.children[ord(each_char) - ord('a')] = new_node
                curr_node = new_node
        curr_node.is_word_end = True
    # print_trie(root, "")
    curr_node = root
    curr_result = ""
    for each_char in query_string:
        if curr_node.children[ord(each_char) - ord('a')] is None:
            return []
        curr_node = curr_node.children[ord(each_char) - ord('a')]
        curr_result += each_char
    queue = collections.deque([])
    queue.append((curr_node, curr_result))
    while queue:
        temp = queue.popleft()
        # print(temp)
        for each_node in temp[0].children:
            # print(each_node)
            if each_node is not None:
                queue.append((each_node, temp[1] + each_node.character))
                if each_node.is_word_end:
                    result.append(temp[1] + each_node.character)
    return result

if __name__ == "__main__":
    print(main(["anuj", "amit", "amitabh", "mayank"], "am"))
